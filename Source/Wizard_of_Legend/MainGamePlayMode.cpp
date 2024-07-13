// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGamePlayMode.h"


AMainGamePlayMode::AMainGamePlayMode()
{
	PlayerControllerClass.GetDefaultObject()->SetShowMouseCursor(true);
	UE_LOG(LogTemp,Warning,TEXT("Mouse stat is %hhd"),PlayerControllerClass.GetDefaultObject()->ShouldShowMouseCursor())
}
