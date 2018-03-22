// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"
//Foward Declaration
class UTankBarrel; 


// Holds barrel's properties and elevare method

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	//TODO add SetTurretReference


	
	void AimAt(FVector OutHitLocation, float LaunchSpeed);

protected:
	


private:

	void MoveBarrelTowards(FVector AimDirection);

	UTankBarrel* Barrel = nullptr;
		
	
};
