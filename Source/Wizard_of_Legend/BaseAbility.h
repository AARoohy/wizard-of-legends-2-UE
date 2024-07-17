#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "UObject/NoExportTypes.h"
#include "BaseAbility.generated.h"

UCLASS(Blueprintable)
class WIZARD_OF_LEGEND_API UBaseAbility : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	FString AbilityName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	int32 AbilityID;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability")
	void ActivateAbility(APlayerCharacter* User);
	virtual void ActivateAbility_Implementation(APlayerCharacter* User);
};
