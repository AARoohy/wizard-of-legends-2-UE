#include "Projectile.h"

#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveInDirection(DeltaTime);
}


void AProjectile::MoveInDirection(float deltaTime)
{
	FVector NewLocation = GetActorLocation() + (Direction * Speed * deltaTime);
	SetActorLocation(NewLocation);
}


void AProjectile::Shoot(AActor* _shooter, float _speed, FVector _direction, float _damage)
{
	Shooter=_shooter;
	Speed=_speed;
	Direction=_direction;
	Damage=_damage;
}
