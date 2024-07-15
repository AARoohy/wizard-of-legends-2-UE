// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AbilityDatabase.generated.h"

UCLASS(BlueprintType)
class WIZARD_OF_LEGEND_API UAbilityDatabase : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TArray<UBaseAbility*> Abilities;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	UBaseAbility* GetAbilityByID(int32 ID) const;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	UBaseAbility* GetAbilityInstanceByID(int32 ID, UObject* Outer) const;
};
