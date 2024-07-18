#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "Slate/SlateBrushAsset.h"
#include "UObject/NoExportTypes.h"
#include "BaseAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCooldownStart, float, cooldown);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilityReady);


UCLASS(Blueprintable)
class WIZARD_OF_LEGEND_API UBaseAbility : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	FString AbilityName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	UTexture2D* AbilityIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	int32 AbilityID;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fireball")
	float CurrentCooldown;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireball")
	float CooldownTime;

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnCooldownStart OnCooldownStart;
	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnAbilityReady OnAbilityReady;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability")
	void Tick(float deltaTime);
	virtual void Tick_Implementation(float deltaTime);

	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability")
	void ActivateAbility(APlayerCharacter* User);
	virtual void ActivateAbility_Implementation(APlayerCharacter* User);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	float GetCooldownPercent(APlayerCharacter* User);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	bool IsOnCooldown;
};
