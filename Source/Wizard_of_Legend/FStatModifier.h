#pragma once

#include "CoreMinimal.h"
#include "EStatsType.h"
#include "FStatModifier.generated.h"


UENUM(BlueprintType)
enum class EModifierType : uint8
{
	Base        UMETA(DisplayName = "Base Value"),
	Direct      UMETA(DisplayName = "Direct Addition"),
	Percentage  UMETA(DisplayName = "Percentage")
};


USTRUCT(BlueprintType)
struct FStatModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
	EStatsType StatType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
	EModifierType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
	float Value;
};

