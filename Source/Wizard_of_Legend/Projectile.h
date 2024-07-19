#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

UCLASS()
class WIZARD_OF_LEGEND_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	AProjectile();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile")
	AActor* Shooter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile")
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile")
	float Damage;

	UFUNCTION(BlueprintCallable, Category="Projectile")
	void MoveInDirection(float deltaTime);

	UFUNCTION(BlueprintCallable, Category="Projectile")
	void Shoot(AActor* _shooter, float _speed, FVector _direction, float _damage);
};
