// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainGamePlayController.generated.h"


UCLASS()
class WIZARD_OF_LEGEND_API AMainGamePlayController : public APlayerController
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Player Character")
	void SetHideCursorDuringCapture(bool hide);

protected:
};
