#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EStatsType : uint8
{
	MoveSpeed        UMETA(DisplayName = "Move Speed"),
	AttackPower      UMETA(DisplayName = "Attack Power"),
	Health           UMETA(DisplayName = "Health"),
};
