#pragma once

#include "CoreMinimal.h"
#include "EStatsType.h"
#include "FStatModifier.h"
#include "Stat.generated.h"


UCLASS(Blueprintable)
class WIZARD_OF_LEGEND_API UStat : public UObject
{
	GENERATED_BODY()

public:
	UStat();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStatChanged, float, OldValue, float, NewValue);

	UPROPERTY(BlueprintAssignable, Category = "Stat")
	FOnStatChanged OnValueChanged;

	UFUNCTION(BlueprintCallable, Category="Stat")
	void AddModifier(const FStatModifier& NewModifier);

	UFUNCTION(BlueprintCallable, Category="Stat")
	float GetValue() const { return Value; }

	UFUNCTION(BlueprintCallable, Category="Stat")
	EStatsType GetStatType() const { return StatType; }

protected:
	UStat(EStatsType InStatType);

	TArray<FStatModifier> Modifiers;
	EStatsType StatType;
	float Value;

	void SetValue(float value);
	virtual float RecalculateValue();
};
