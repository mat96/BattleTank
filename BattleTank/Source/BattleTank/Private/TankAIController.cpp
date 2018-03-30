// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"




void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(GetPlayerTank()) 
	{
		//TODO Move Towards the Player

		// Aim Towards the player
	
		 GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if Ready
	
	}

}

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller find player tank "),)
	}
	else if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller cannot find player tank"), *(PlayerTank->GetName()))
	}

}


ATank* ATankAIController::GetAIController() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;}

	
	return Cast<ATank>(PlayerPawn);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

	
