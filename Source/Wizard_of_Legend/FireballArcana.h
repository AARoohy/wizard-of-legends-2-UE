#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "FireballArcana.generated.h"

UCLASS(Blueprintable)
class WIZARD_OF_LEGEND_API UFireballArcana : public UBaseAbility
{
	GENERATED_BODY()

public:
	UFireballArcana();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	float FirstSecondProjectileDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	float ThirdProjectileDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	float CooldownTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	float ThirdProjectileDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	float CycleResetTime;

	UFUNCTION(BlueprintCallable, Category = "Fireball")
	virtual void ActivateAbility_Implementation(AActor* User) override;

private:
	int32 ProjectileCount;
	FTimerHandle ResetCycleTimerHandle;
	FTimerHandle CooldownTimerHandle;
	
	bool bIsOnCooldown;

	void ResetCycle();
	void EndCooldown();
};
