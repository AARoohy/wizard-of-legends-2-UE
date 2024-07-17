// Fill out your copyright notice in the Description page of Project Settings.


#include "FocusableListWidget.h"

#include "Components/PanelWidget.h"

void UFocusableListWidget::Setup()
{
	Super::NativeConstruct();

	CurrentIndex = -1;
	for (int32 i = 0; i < MenuWidgets.Num(); ++i)
	{
		UFocusableElementWidget* ChildWidget = MenuWidgets[i];
		if (ChildWidget == CurrentFocusedWidget)
			CurrentIndex = i;
		ChildWidget->OnMouseEnterDelegate.AddDynamic(this, &UFocusableListWidget::OnWidgetHovered);
	}
	if (CurrentIndex == -1)
		CurrentIndex = 0;

	SetFocus(CurrentIndex);
	UE_LOG(LogTemp, Error, TEXT("No attackpower stat found"));
}

void UFocusableListWidget::SetFocus(int index)
{
	CurrentIndex = index;
	for (int32 i = 0; i < MenuWidgets.Num(); ++i)
	{
		UFocusableElementWidget* ChildWidget = MenuWidgets[i];
		if (i == CurrentIndex)
		{
			ChildWidget->SetKeyboardFocus();
			ChildWidget->SetFocusOn();
		}
		else
			ChildWidget->SetFocusOff();
	}
}

void UFocusableListWidget::SetFocus(UFocusableElementWidget* target)
{
	for (int32 i = 0; i < MenuWidgets.Num(); ++i)
	{
		UFocusableElementWidget* ChildWidget = MenuWidgets[i];
		if (ChildWidget == target)
		{
			CurrentIndex = i;
			ChildWidget->SetKeyboardFocus();
			ChildWidget->SetFocusOn();
		}
		else
			ChildWidget->SetFocusOff();
	}
}


void UFocusableListWidget::OnWidgetHovered(UFocusableElementWidget* HoveredWidget)
{
	SetFocus(HoveredWidget);
}

FReply UFocusableListWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	Super::NativeOnKeyDown(InGeometry, InKeyEvent);

	UE_LOG(LogTemp, Error, TEXT("No attackpower stat found"));
	int nextIndex = CurrentIndex;
	FKey key = InKeyEvent.GetKey();
	if (key == EKeys::Down)
		nextIndex++;
	else if (key == EKeys::Up)
		nextIndex--;
	nextIndex = FMath::Clamp(nextIndex, 0, MenuWidgets.Num());
	if (nextIndex != CurrentIndex)
		SetFocus(nextIndex);
	return FReply::Unhandled();
}
