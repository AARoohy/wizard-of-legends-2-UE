
#include "FireballArcanaProjectile.h"

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

void AFireballArcanaProjectile::FireInDirection(const FVector& ShootDirection)
{
	//ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

