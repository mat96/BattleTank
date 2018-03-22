// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20; // Sensible default value
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationInDegrees;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationInDegrees;
	
	
	
};
