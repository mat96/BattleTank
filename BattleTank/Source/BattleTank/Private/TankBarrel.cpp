// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "BattleTank.h"
#include "Engine/World.h"





void UTankBarrel::Elevate(float RelativeSpeed)
{


	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	// given a max elevation speed 
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationInDegrees, MaxElevationInDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));




}
