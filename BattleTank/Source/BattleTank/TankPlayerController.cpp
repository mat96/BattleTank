// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerControllers::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
	
}


void ATankPlayerControllers::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayController not possessing a tank"))

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is possesing %s"), *ControlledTank->GetName())
	}
}




ATank* ATankPlayerControllers::GetControlledTank() const
{

	return	Cast<ATank>(GetPawn());
}

void ATankPlayerControllers::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; // Out Parameter
	if (GetSightRayHitLocation(OutHitLocation))
	{
		
		GetControlledTank()->AimAt(OutHitLocation);
	}

		// if it hits the landscape
			// Tell Control tank to aim at this point

	
}
// Get world location through crosshair, true if it hits landscape
bool ATankPlayerControllers::GetSightRayHitLocation(FVector& OutHitLocation) const
{

	//Find the crosshair possition
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	

	// Deproject screen projection 
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line-Trace along that LookDirection, and see what we hit (up to max range)
		GetLookVectorHitLocation( LookDirection, OutHitLocation);

	}

	

	return true;

	
}

bool ATankPlayerControllers::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{

	FVector CameraWorldLocation;
	FVector WorldDirection; // OUT Parameter 

	return DeprojectScreenPositionToWorld(ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
	
		
}

bool ATankPlayerControllers::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;

	}
	else
	{
		OutHitLocation = FVector (0);
		return false;
	}
	
	

}



