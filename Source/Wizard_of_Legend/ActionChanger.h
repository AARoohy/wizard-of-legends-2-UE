// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Widget.h"
#include "Input/UIActionBindingHandle.h"
#include "ActionChanger.generated.h"



UCLASS()
class WIZARD_OF_LEGEND_API UActionChanger : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CommonActionWidget, meta = (EditCondition = "CommonInput.CommonInputSettings.IsEnhancedInputSupportEnabled", EditConditionHides))
	TObjectPtr<class UInputAction> EnhancedInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CommonActionWidget, meta = (RowType = "/Script/CommonUI.CommonInputActionDataBase", TitleProperty = "RowName"))
	TArray<FDataTableRowHandle> InputActions;
	
	UFUNCTION(BlueprintCallable, Category = "Action Change Checker")
	FSlateBrush GetIcon();
	
	//UCommonInputSubsystem* GetInputSubsystem() const;
};
