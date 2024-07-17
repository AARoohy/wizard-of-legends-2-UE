// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FocusableElementWidget.h"
#include "Blueprint/UserWidget.h"
#include "FocusableListWidget.generated.h"

UCLASS()
class WIZARD_OF_LEGEND_API UFocusableListWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Focusable")
	TArray<UFocusableElementWidget*> MenuWidgets;
	
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Focusable")
	UFocusableElementWidget* CurrentFocusedWidget;

	UFUNCTION(BlueprintCallable, Category = "Focusable")
	void Setup();
	
protected:
	UFUNCTION()
	void OnWidgetHovered(UFocusableElementWidget* HoveredWidget);
	
private:
	int CurrentIndex;
	void NavigateToNextWidget();
	void NavigateToPreviousWidget();

	void SetFocus(int index);
	void SetFocus(UFocusableElementWidget* target);
};
