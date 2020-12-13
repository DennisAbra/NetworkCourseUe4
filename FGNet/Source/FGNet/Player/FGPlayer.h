#pragma once

#include "GameFramework/Pawn.h"
#include "FGPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UFGMovementComponent;
class UStaticMeshComponent;
class USphereComponent;
class UFGPlayerSettings;
class UFGNetDebugWidget;
class AFGPickup;
class AFGRocket;



UCLASS()
class FGNET_API AFGPlayer : public APawn
{
	GENERATED_BODY()

public:
	AFGPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Settings)
	UFGPlayerSettings* PlayerSettings = nullptr;

	UFUNCTION(BlueprintPure)
		bool IsBraking() const { return bBrake; }

	UFUNCTION(BlueprintPure)
		int32 GetPing() const;

	UPROPERTY(EditAnywhere, Category = Debug)
	TSubclassOf<UFGNetDebugWidget> DebugMenuClass;

	UFUNCTION(Server, Unreliable)
		void Server_SendYaw(float InYaw);

	UFUNCTION(Server, Unreliable)
		void Server_SendLocation(const FVector& LocationToSend);

	void OnPickup(AFGPickup* Pickup);

	UFUNCTION(Server, Unreliable)
	void Server_OnPickup(AFGPickup* Pickup);

	UFUNCTION(Client, Reliable)
	void Client_OnPickupRockets(int32 PickedUpRockets);

	UFUNCTION(NetMulticast, Reliable)
	void MultiCast_OnPickupRockets(int32 PickedUpRockets);

	UFUNCTION(NetMulticast, Unreliable)
	void Multicast_SendLocation(const FVector& LocationToSend);

	void ShowDebugMenu();
	void HideDebugMenu();

	UFUNCTION(Server, Unreliable)
		void Server_SendRotation(const FRotator& RotationToSend);

	UFUNCTION(NetMulticast, Unreliable)
		void MultiCast_SendRotation(const FRotator& RotationToSend);

	UFUNCTION(BlueprintPure)
	int32 GetNumRockets() const { return NumRockets;}

	UFUNCTION(BlueprintImplementableEvent, Category = Player, meta = (DisplayName = "On Num Rockets Changed"))
	void BP_OnNumRcketsChanged(int32 NewNumRockets);

	int32 GetNumActiveRockets() const;

	void FireRocket();

	void SpawnRockets();

	UFUNCTION(BlueprintImplementableEvent, Category = Health)
	void BP_OnHealthChanged(int32 Health);

	UFUNCTION(BlueprintCallable)
		void OnTakeDamage(int32 DamageToTake);

private:

	UFUNCTION(Server, Reliable)
	void Server_TakeDamage(int32 DamageTaken);

	UFUNCTION(Client, Reliable)
	void Client_TakeDamage(int32 NewHealth);

	UFUNCTION(NetMulticast, Reliable)
	void MultiCast_TakeDamage(int32 DamageToTake);



	int32 ServerCurrentHealth = 0;

	UPROPERTY(Replicated)
	int32 CurrentHealth = 0;

	UPROPERTY(EditAnywhere, Category = Health)
	int32 MaxHealth;

	int32 ServerNumRocket = 0;

	UPROPERTY(Replicated)
	int32 NumRockets = 0;

	FVector GetRocketStartLocation() const;

	AFGRocket* GetFreeRocket() const;

	UFUNCTION(Server, Reliable)
	void Server_FireRocket(AFGRocket* NewRocket, const FVector& RocketStartLocation, const FRotator& RocketFacingDirection);

	UFUNCTION(NetMulticast, Reliable)
	void MultiCast_FireRocket(AFGRocket* NewRocket, const FVector& RocketStartLocation, const FRotator& RocketFacingDirection);

	UFUNCTION(Client, Reliable)
	void Client_RemoveRocket(AFGRocket* RocketToRemove);

	UFUNCTION(BlueprintCallable)
	void Cheat_IncreaseRockets(int32 InNumRockets);

	UPROPERTY(Replicated, Transient)
	TArray<AFGRocket*> RocketInstances;

	UPROPERTY(EditAnywhere, Category = Weapon)
	TSubclassOf<AFGRocket> RocketClass;

	int32 MaxActiveRockets = 3;

	float FireCooldownElapsed = 0.0f;

	UPROPERTY(EditAnywhere, Category = Weapon)
	bool bUnlimitedRockets = false;
 

	void Handle_Accelerate(float Value);
	void Handle_Turn(float Value);
	void Handle_BrakePressed();
	void Handle_BrakeReleased();

	void Handle_DebugMenuPressed();
	void CreateDebugWidget();

	void Handle_FirePressed();

	bool bShowDebugMenu = false;

	UPROPERTY(Replicated)
	float ReplicatedYaw = 0.0f;

	UPROPERTY(Replicated)
	FVector ReplicatedLocation;

	UPROPERTY(Transient)
	UFGNetDebugWidget* DebugMenuInstance = nullptr;

	FRotator InterpTargetRot;
	FVector InterpTargetLoc;

	UPROPERTY(EditAnywhere, Category = Movement)
	float RotationSpeed = 0.0f;

	UPROPERTY(EditAnywhere, Category = Movement)
		float LocationSpeed = 0.0f;

	float Forward = 0.0f;
	float Turn = 0.0f;

	float MovementVelocity = 0.0f;
	float Yaw = 0.0f;

	bool bBrake = false;

	UPROPERTY(VisibleDefaultsOnly, Category = Collision)
		USphereComponent* CollisionComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Camera)
		USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Camera)
		UCameraComponent* CameraComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Movement)
		UFGMovementComponent* MovementComponent;

};

