
#include "FireballArcanaProjectile.h"

#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AFireballArcanaProjectile::AFireballArcanaProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AFireballArcanaProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFireballArcanaProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AFireballArcanaProjectile::MoveInDirection(float deltaTime)
{
	FVector NewLocation = GetActorLocation() + (Direction * Speed * deltaTime);
	SetActorLocation(NewLocation);
}


