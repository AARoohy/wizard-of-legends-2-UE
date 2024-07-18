// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

FVector APlayerCharacter::DirectionBasedOnCamera(FVector InputDirection, UCameraComponent* CameraComponent)
{
	if (Controller == nullptr || (InputDirection.X == 0.0f && InputDirection.Y == 0.0f))
	{
		return FVector(0.0f, 0.0f,0.0f);
	}

	FVector Forward = CameraComponent->GetForwardVector();
	FVector Right = CameraComponent->GetRightVector();

	Forward.Z = 0;
	Forward.Normalize();

	Right.Normalize();

	FVector MoveDirection = Forward * InputDirection.X + Right * InputDirection.Y;
	MoveDirection.Normalize();

	return MoveDirection;
}
