// Copyright Epic Games, Inc. All Rights Reserved.

#include "Wizard_of_LegendGameMode.h"
#include "Wizard_of_LegendPlayerController.h"
#include "Wizard_of_LegendCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWizard_of_LegendGameMode::AWizard_of_LegendGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AWizard_of_LegendPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}