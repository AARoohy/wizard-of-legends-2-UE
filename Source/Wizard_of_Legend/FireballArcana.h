#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "Projectile.h"
#include "FireballArcana.generated.h"

UCLASS(Blueprintable)
class WIZARD_OF_LEGEND_API AFireballArcana : public ABaseAbility
{
	GENERATED_BODY()

public:
	AFireballArcana();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	FVector FireBallSpawnDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	float FireBallSpeed;
	
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	float ThirdProjectileDamageMulti;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	float ThirdProjectileDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	float CycleResetTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	UDamageType* DamageType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	TSubclassOf<AProjectile> FireballClass;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fireball")
	float currentResetTimer;

	virtual void OnActivateAbility_Implementation() override;

	virtual void Tick_Implementation(float deltaTime) override;


private:
	int32 ProjectileCount;
	FTimerHandle ResetCycleTimerHandle;
	FTimerHandle CooldownTimerHandle;


	void ResetCycle();
	void EndCooldown();
};
