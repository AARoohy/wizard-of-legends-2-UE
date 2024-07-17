// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FocusableElementWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMouseEnterDelegate,UFocusableElementWidget*,element);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMouseExitDelegate,UFocusableElementWidget*,element);

UCLASS(Abstract)
class WIZARD_OF_LEGEND_API UFocusableElementWidget : public UUserWidget
{
	GENERATED_BODY()

public:
public:
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnMouseEnterDelegate OnMouseEnterDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnMouseExitDelegate OnMouseExitDelegate;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Focus")
	void SetFocusOn();
	virtual void SetFocusOn_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Focus")
	void SetFocusOff();
	virtual void SetFocusOff_Implementation();

protected:
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
};
