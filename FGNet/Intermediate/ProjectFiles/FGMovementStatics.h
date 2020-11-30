#pragma once

#include "CoreMinimal.h"

class AActor;
class USceneComponent;

struct FFGFrameMovement
{
	FFGFrameMovement(const FVector& InStartLocation) : StartLocation(InStartLocation) {}

	FFGFrameMovement(AActor* InActor);
	FFFGFrameMovement(USceneComponent* InSceneComponent);

	void AddDelta(const FVector& InDelta);

	FVector GetMovementDelsta() const { return MovementDelta; }

	FHitResult Hit;
	FVector FinalLocation = FVector::ZeroVector;

private:
	FVector MovementDelta = FVector::ZeroVector;
	FVector StartLocation = FVector::ZeroVector;
};
