// Fill out your copyright notice in the Description page of Project Settings.


#include "FocusableElementWidget.h"

void UFocusableElementWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

	OnMouseEnterDelegate.Broadcast(this);
}

void UFocusableElementWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);

	OnMouseExitDelegate.Broadcast(this);
}


void UFocusableElementWidget::SetFocusOn_Implementation()
{
}

void UFocusableElementWidget::SetFocusOff_Implementation()
{
}
