#include "FGPlayer.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/NetDriver.h"
#include "GameFramework/PlayerState.h"
#include "../Components/FGMovementComponent.h"
#include "../FGMovementStatics.h"
#include "Net/UnrealNetWork.h"
#include "FGPlayerSettings.h"
#include "../Debug/UI/FGNetDebugWidget.h"
#include "../FGPickup.h"
#include "../FGRocket.h"

AFGPlayer::AFGPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	RootComponent = CollisionComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(CollisionComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->bInheritYaw = false;
	SpringArmComponent->SetupAttachment(CollisionComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	MovementComponent = CreateDefaultSubobject<UFGMovementComponent>(TEXT("MovementComponent"));

	SetReplicateMovement(false);
}

void AFGPlayer::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	ServerCurrentHealth = MaxHealth;
	BP_OnHealthChanged(CurrentHealth);

	MovementComponent->SetUpdatedComponent(CollisionComponent);
	CreateDebugWidget();
	if (DebugMenuInstance != nullptr)
	{
		DebugMenuInstance->SetVisibility(ESlateVisibility::Collapsed);
	}

	SpawnRockets();
}

void AFGPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FireCooldownElapsed -= DeltaTime;

	if (!ensure(PlayerSettings != nullptr))
		return;
	if (IsLocallyControlled())
	{
		const float Friction = IsBraking() ? PlayerSettings->BrakingFriction : PlayerSettings->Friction;
		const float Alpha = FMath::Clamp(FMath::Abs(MovementVelocity / (PlayerSettings->MaxVelocity * 0.75f)), 0.0f, 1.0f);
		const float TurnSpeed = FMath::InterpEaseOut(0.0f, PlayerSettings->TurnSpeedDefault, Alpha, 5.0f);
		const float MovementDirection = MovementVelocity > 0.0f ? Turn : -Turn;

		Yaw += (MovementDirection * TurnSpeed) * DeltaTime;
		FQuat WantedFacingDirection = FQuat(FVector::UpVector, FMath::DegreesToRadians(Yaw));
		MovementComponent->SetFacingRotation(WantedFacingDirection);

		FFGFrameMovement FrameMovement = MovementComponent->CreateFrameMovement();

		MovementVelocity += Forward * PlayerSettings->Acceleration * DeltaTime;
		MovementVelocity = FMath::Clamp(MovementVelocity, -PlayerSettings->MaxVelocity, PlayerSettings->MaxVelocity);
		MovementVelocity *= FMath::Pow(Friction, DeltaTime);

		MovementComponent->ApplyGravity();
		FrameMovement.AddDelta(GetActorForwardVector() * MovementVelocity * DeltaTime);
		MovementComponent->Move(FrameMovement);

		Server_SendLocation(GetActorLocation());
		//Server_SendRotation(GetActorRotation());
		Server_SendYaw(MovementComponent->GetFacingRotation().Yaw);
	}
	else
	{
		const FVector NewLoc = FMath::VInterpTo(GetActorLocation(), ReplicatedLocation, DeltaTime, LocationSpeed);
		SetActorLocation(NewLoc);
		const FRotator NewRot = FMath::RInterpTo(GetActorRotation(), FRotator(0.0f, ReplicatedYaw, 0.0f), DeltaTime, RotationSpeed);
		SetActorRotation(NewRot);
		//MovementComponent->SetFacingRotation(FRotator(0.0f, ReplicatedYaw, 0.0f), 7.0f);
		//SetActorRotation(MovementComponent->GetFacingRotation());
	}

}

void AFGPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Accelerate"), this, &AFGPlayer::Handle_Accelerate);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AFGPlayer::Handle_Turn);

	PlayerInputComponent->BindAction(TEXT("Brake"), IE_Pressed, this, &AFGPlayer::Handle_BrakePressed);
	PlayerInputComponent->BindAction(TEXT("Brake"), IE_Released, this, &AFGPlayer::Handle_BrakeReleased);
	PlayerInputComponent->BindAction(TEXT("DebugMenu"), IE_Pressed, this, &AFGPlayer::Handle_DebugMenuPressed);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AFGPlayer::Handle_FirePressed);
}

int32 AFGPlayer::GetPing() const
{
	if (GetPlayerState())
	{
		return static_cast<int32>(GetPlayerState()->GetPing());
	}
	return 0;
}

void AFGPlayer::Server_SendYaw_Implementation(float InYaw)
{
	ReplicatedYaw = InYaw;
}

void AFGPlayer::OnPickup(AFGPickup* Pickup)
{
	if(IsLocallyControlled())
		Server_OnPickup(Pickup);
}

void AFGPlayer::Server_TakeDamage_Implementation(int32 DamageTaken)
{
	ServerCurrentHealth -= DamageTaken;
	Client_TakeDamage(ServerCurrentHealth);
	MultiCast_TakeDamage(DamageTaken);
}

void AFGPlayer::Client_TakeDamage_Implementation(int32 NewHealth)
{
	CurrentHealth = NewHealth;
	BP_OnHealthChanged(CurrentHealth);
}

void AFGPlayer::MultiCast_TakeDamage_Implementation(int32 DamageToTake)
{
	if (!IsLocallyControlled())
	{
		CurrentHealth -= DamageToTake;
		BP_OnHealthChanged(CurrentHealth);
	}
}

void AFGPlayer::OnTakeDamage(int32 DamageToTake)
{
	if(IsLocallyControlled())
	Server_TakeDamage(DamageToTake);
}

void AFGPlayer::Server_OnPickup_Implementation(AFGPickup* Pickup)
{
	ServerNumRocket += Pickup->NumRockets;
	Client_OnPickupRockets(Pickup->NumRockets);
	MultiCast_OnPickupRockets(Pickup->NumRockets);
}

void AFGPlayer::Client_OnPickupRockets_Implementation(int32 PickedUpRockets)
{
	NumRockets += PickedUpRockets;
	BP_OnNumRcketsChanged(NumRockets);
}

void AFGPlayer::MultiCast_OnPickupRockets_Implementation(int32 PickedUpRockets)
{
	if (!IsLocallyControlled())
	{
		NumRockets += PickedUpRockets;
		BP_OnNumRcketsChanged(NumRockets);
	}
}

void AFGPlayer::ShowDebugMenu()
{
	CreateDebugWidget();
	DebugMenuInstance->SetVisibility(ESlateVisibility::Visible);
	DebugMenuInstance->BP_OnShowWidget();
}

void AFGPlayer::HideDebugMenu()
{
	if (DebugMenuInstance == nullptr)
		return;

	DebugMenuInstance->SetVisibility(ESlateVisibility::Collapsed);
	DebugMenuInstance->BP_OnHideWidget();
}

void AFGPlayer::Server_SendLocation_Implementation(const FVector& LocationToSend)
{
	ReplicatedLocation = LocationToSend;
}

void AFGPlayer::Multicast_SendLocation_Implementation(const FVector& LocationToSend)
{
	if (!IsLocallyControlled())
		InterpTargetLoc = LocationToSend;
}

void AFGPlayer::Server_SendRotation_Implementation(const FRotator& RotationToSend)
{
	MultiCast_SendRotation(RotationToSend);
}

void AFGPlayer::MultiCast_SendRotation_Implementation(const FRotator& RotationToSend)
{
	if (!IsLocallyControlled())
		InterpTargetRot = RotationToSend;
}

void AFGPlayer::Handle_Accelerate(float Value)
{
	Forward = Value;
}

void AFGPlayer::Handle_Turn(float Value)
{
	Turn = Value;
}

void AFGPlayer::Handle_BrakePressed()
{
	bBrake = true;
}

void AFGPlayer::Handle_BrakeReleased()
{
	bBrake = false;
}

void AFGPlayer::Handle_DebugMenuPressed()
{
	bShowDebugMenu = !bShowDebugMenu;
	if (bShowDebugMenu)
		ShowDebugMenu();
	else
		HideDebugMenu();
}

void AFGPlayer::CreateDebugWidget()
{
	if (DebugMenuClass == nullptr)
		return;

	if (!IsLocallyControlled())
		return;

	if (DebugMenuInstance == nullptr)
	{
		DebugMenuInstance = CreateWidget<UFGNetDebugWidget>(GetWorld(), DebugMenuClass);
		DebugMenuInstance->AddToViewport();
	}
}

void AFGPlayer::Handle_FirePressed()
{
	FireRocket();
}

AFGRocket* AFGPlayer::GetFreeRocket() const 
{
	for (AFGRocket* Rocket : RocketInstances)
	{
		if (Rocket == nullptr)
			continue;

		if (Rocket->IsFree())
			return Rocket;
	}

	return nullptr;
}

FVector AFGPlayer::GetRocketStartLocation() const 
{
	const FVector StartLoc = GetActorLocation() + GetActorForwardVector() * 100.0f;
	return StartLoc;
}

void AFGPlayer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const 
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFGPlayer, ReplicatedYaw);
	DOREPLIFETIME(AFGPlayer, ReplicatedLocation);
	DOREPLIFETIME(AFGPlayer, RocketInstances);
	DOREPLIFETIME(AFGPlayer, NumRockets);
	DOREPLIFETIME(AFGPlayer, CurrentHealth);

}

int32 AFGPlayer::GetNumActiveRockets() const
{
	int32 NumActive = 0;
	for (AFGRocket* Rocket : RocketInstances)
	{
		if (!Rocket->IsFree())
			NumActive++;
	}

	return NumActive;
}

void AFGPlayer::FireRocket()
{
	if (FireCooldownElapsed > 0.0f)
		return;
	if (NumRockets <= 0 && !bUnlimitedRockets)
		return;
	if (GetNumActiveRockets() >= MaxActiveRockets)
		return;

	AFGRocket* NewRocket = GetFreeRocket();
	if (!ensure(NewRocket != nullptr))
		return;

	FireCooldownElapsed = PlayerSettings->FireCooldown;

	if (GetLocalRole() >= ROLE_AutonomousProxy)
	{
		if (HasAuthority())
		{
			Server_FireRocket(NewRocket, GetRocketStartLocation(), GetActorRotation());
		}
		else
		{
			NumRockets--;
			BP_OnNumRcketsChanged(NumRockets);
			NewRocket->StartMoving(GetActorForwardVector(), GetRocketStartLocation());
			Server_FireRocket(NewRocket, GetRocketStartLocation(), GetActorRotation());
		}
	}
}

void AFGPlayer::Server_FireRocket_Implementation(AFGRocket* NewRocket, const FVector& RocketStartLocation, const FRotator& RocketFacingDirection)
{
	if ((ServerNumRocket - 1) < 0 && !bUnlimitedRockets)
	{
		Client_RemoveRocket(NewRocket);
	}
	else
	{
		const float DeltaYaw = FMath::FindDeltaAngleDegrees(RocketFacingDirection.Yaw, GetActorForwardVector().Rotation().Yaw) * 0.5f;
		const FRotator NewFacingRotation = RocketFacingDirection + FRotator(0.0f, DeltaYaw, 0.0f);
		ServerNumRocket--;
		MultiCast_FireRocket(NewRocket, RocketStartLocation, NewFacingRotation);
	}
}

void AFGPlayer::Client_RemoveRocket_Implementation(AFGRocket* RocketToRemove)
{
	RocketToRemove->MakeFree();
}

void AFGPlayer::MultiCast_FireRocket_Implementation(AFGRocket* NewRocket, const FVector& RocketStartLocation, const FRotator& RocketFacingDirection)
{
	if (!ensure(NewRocket != nullptr))
		return;

	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		NewRocket->ApplyCorrection(RocketFacingDirection.Vector());
	}
	else
	{
		NumRockets--;
		BP_OnNumRcketsChanged(NumRockets);
		NewRocket->StartMoving(RocketFacingDirection.Vector(), RocketStartLocation);
	}
}

void AFGPlayer::Cheat_IncreaseRockets(int32 InNumRockets)
{
}

void AFGPlayer::SpawnRockets()
{
	if (HasAuthority() && RocketClass != nullptr)
	{
		const int32 RocketCache = 8;

		for (int32 Index = 0; Index < RocketCache; ++Index)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
			SpawnParams.ObjectFlags = RF_Transient;
			SpawnParams.Instigator = this;
			SpawnParams.Owner = this;
			AFGRocket* NewRocketInstance = GetWorld()->SpawnActor<AFGRocket>(RocketClass, GetActorLocation(), GetActorRotation(), SpawnParams);
			RocketInstances.Add(NewRocketInstance);
		}
	}
}




