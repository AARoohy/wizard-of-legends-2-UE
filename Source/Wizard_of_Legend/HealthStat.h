#pragma once

#include "CoreMinimal.h"
#include "Stat.h"
#include "HealthStat.generated.h"

UCLASS()
class WIZARD_OF_LEGEND_API UHealthStat : public UStat
{
	GENERATED_BODY()

public:
	UHealthStat();
	virtual float RecalculateValue() override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStatChanged, float, OldValue, float, NewValue);
	UPROPERTY(BlueprintAssignable, Category = "Stat|Health Stat")
	FOnStatChanged OnCurrentHealthChanged;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDied);
	UPROPERTY(BlueprintAssignable, Category = "Stat|Health Stat")
	FOnDied OnDied;

	UFUNCTION(BlueprintCallable, Category = "Stat|Health Stat")
	void SetCurrentHealth(float amount);

	UFUNCTION(BlueprintCallable, Category = "Stat|Health Stat")
	void DecreaseCurrentHealth(float amount);

	UFUNCTION(BlueprintCallable, Category = "Stat|Health Stat")
	void IncreaseCurrentHealth(float amount);

	UFUNCTION(BlueprintCallable, Category = "Stat|Health Stat")
	float GetCurrentHealth() const { return currentHealth; }

	UFUNCTION(BlueprintCallable, Category = "Stat|Health Stat")
	bool GetIsDead() const { return isDead; }

private:
	float currentHealth;
	bool isDead;

	void CheckDeath();
};
