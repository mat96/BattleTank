// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"




void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Player Pawn
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (!PlayerTank) { return; }

	if (PlayerTank) 
	{
		//TODO Move Towards the Player
		MoveToActor(PlayerTank, AcceptanceRadius);
		// Aim Towards the player
	
		 ControlledTank->AimAt(PlayerTank->GetActorLocation());
		 ControlledTank->fire(); //TODO dont fire everyframe
	
	}

}

void ATankAIController::BeginPlay()
{

	Super::BeginPlay();
	


}



