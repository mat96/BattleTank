// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::InitializeComponent(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{

	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);
	
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO prevent double-speed 
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{

	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	//TODO prevent double-speed 
}

//To make the AI tank find the player and move towards the player
void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	
	//No need to call Super as we're replaceing functionality
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
//	UE_LOG(LogTemp, Warning, TEXT("%s has the value of %s "), *TankName, *MoveVelocityString)

  auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
  auto CrossProduct = FVector::CrossProduct(TankForward, AIForwardIntention);

  IntendMoveRight(CrossProduct.Z);
  IntendMoveForward(ForwardThrow);
} 


