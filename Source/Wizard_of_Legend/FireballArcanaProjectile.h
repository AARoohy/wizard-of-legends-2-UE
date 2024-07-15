#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireballArcanaProjectile.generated.h"

UCLASS()
class WIZARD_OF_LEGEND_API AFireballArcanaProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AFireballArcanaProjectile();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void FireInDirection(const FVector& ShootDirection);
};
