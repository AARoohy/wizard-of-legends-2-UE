#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "StatContainer.h"
#include "Slate/SlateBrushAsset.h"
#include "UObject/NoExportTypes.h"
#include "BaseAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCooldownStart, float, cooldown);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilityReady);

UCLASS(Blueprintable)
class WIZARD_OF_LEGEND_API ABaseAbility : public AActor
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	float CurrentCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	float CooldownTime;

	UPROPERTY(BlueprintReadOnly,BlueprintAssignable, Category = "Ability")
	FOnCooldownStart OnCooldownStart;
	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnAbilityReady OnAbilityReady;
	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnAbilityReady OnCooldownWarning;


	UFUNCTION(BlueprintCallable, Category = "Ability")
	virtual void Setup(APlayerCharacter* User);


	UFUNCTION(BlueprintCallable, Category = "Ability")
	void ActivateAbility();
	


	UFUNCTION(BlueprintCallable, Category = "Ability")
	float GetCooldownPercent();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	virtual void StartCooldown();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	virtual void EndCooldown();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	bool GetIsOnCooldown();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	UStatContainer* StatContainer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	APlayerCharacter* CurrentUser;
	
	UFUNCTION(BlueprintNativeEvent, Category = "Ability")
	void OnActivateAbility();
	virtual void OnActivateAbility_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability")
	void Tick(float deltaTime);
	virtual void Tick_Implementation(float deltaTime);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability")
	void OnSetup(APlayerCharacter* user);
	virtual void OnSetup_Implementation(APlayerCharacter* user);

};
