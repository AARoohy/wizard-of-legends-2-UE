#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "FireballArcanaProjectile.h"
#include "FireballArcana.generated.h"

UCLASS(Blueprintable)
class WIZARD_OF_LEGEND_API UFireballArcana : public UBaseAbility
{
	GENERATED_BODY()

public:
	UFireballArcana();

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
	TSubclassOf<AFireballArcanaProjectile> FireballClass;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fireball")
	float currentResetTimer;

	UFUNCTION(BlueprintCallable, Category = "Fireball")
	virtual void ActivateAbility_Implementation(APlayerCharacter* User) override;

	UFUNCTION(BlueprintCallable, Category = "Fireball")
	virtual void Tick_Implementation(float deltaTime) override;


private:
	int32 ProjectileCount;
	FTimerHandle ResetCycleTimerHandle;
	FTimerHandle CooldownTimerHandle;


	void ResetCycle();
	void EndCooldown();
};
