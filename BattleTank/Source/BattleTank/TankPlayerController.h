// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"



UCLASS()
class BATTLETANK_API ATankPlayerControllers : public APlayerController 
{
	GENERATED_BODY()
	
public: 
	
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	

private:

	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();


	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	//LineTraceRange Parameters
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 10000000.0;

	// Cross hair blueprint parameters
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;
};


