#include "FGPickup.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Player/FGPlayer.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "DrawDebugHelpers.h"

AFGPickup::AFGPickup()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetGenerateOverlapEvents(false);
	MeshComponent->SetCollisionProfileName(TEXT("NoCollision"));

	SetReplicates(true);
	bReplicateSetActorHiddenInGame = false;

}

void AFGPickup::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AFGPickup::OverlapBegin);
	CachedMeshRelativeLocation = MeshComponent->GetRelativeLocation();
}

void AFGPickup::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (const UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(ReActivateHandle);
	}
}

void AFGPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float PulsatingValue = FMath::MakePulsatingValue(GetWorld()->GetTimeSeconds(), 0.65f) * 30.0f;
	const FVector NewLocation = CachedMeshRelativeLocation + FVector(0.0f, 0.0f, PulsatingValue);
	FHitResult Hit;
	MeshComponent->SetRelativeLocation(NewLocation, false, &Hit, ETeleportType::TeleportPhysics);
	MeshComponent->AddRelativeRotation(FRotator(0.0f, 20.0f * DeltaTime, 0.0f), false, &Hit, ETeleportType::TeleportPhysics);
}

void AFGPickup::DeActivatePickup()
{
	bPickedUp = true;
	SphereComponent->SetCollisionProfileName(TEXT("NoCollision"));
	//RootComponent->SetVisibility(false, true);
	bReplicateSetActorHiddenInGame = true;
	SetActorHiddenInGame(true);
	GetWorldTimerManager().SetTimer(ReActivateHandle, this, &AFGPickup::ReActivatePickup, ReActivateTime, false);
	SetActorTickEnabled(false);
}

void AFGPickup::ReActivatePickup()
{
	bPickedUp = false;
	//RootComponent->SetVisibility(true, true);
	bReplicateSetActorHiddenInGame = true;
	SetActorHiddenInGame(false);
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	SetActorTickEnabled(true);
}

void AFGPickup::OverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bSweep, const FHitResult& SweepResult)
{
	if (bPickedUp)
		return;

	if (AFGPlayer* Player = Cast<AFGPlayer>(OtherActor))
	{
		Player->OnPickup(this);
	}
}