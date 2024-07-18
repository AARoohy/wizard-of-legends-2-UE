// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGamePlayController.h"

void AMainGamePlayController::SetHideCursorDuringCapture(bool hide)
{
	UGameViewportClient* GameViewportClient=GetWorld()->GetGameViewport();
	GameViewportClient->SetHideCursorDuringCapture(hide);
}


