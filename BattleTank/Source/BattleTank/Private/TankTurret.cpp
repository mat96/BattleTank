// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"


void UTankTurret::TurnTurret(float TurretRotation)
{
	TurretRotation = FMath::Clamp<float>(TurretRotation, -1, 1);
	auto RotationChange = TurretRotation * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	 auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));



}


