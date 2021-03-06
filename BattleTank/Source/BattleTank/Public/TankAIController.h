// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
		virtual void BeginPlay() override;

private:
	//How close can the AI can get to the player
	float AcceptanceRadius = 3000;
	
};
