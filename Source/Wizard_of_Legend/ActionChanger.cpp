// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionChanger.h"
#include "GameplayTagsManager.h"

FSlateBrush UActionChanger::GetIcon()
{
	/*if (const UCommonInputSubsystem* CommonInputSubsystem = GetInputSubsystem())
	{
		return EnhancedInputAction && CommonUI::IsEnhancedInputSupportEnabled()
			       ? CommonUI::GetIconForEnhancedInputAction(CommonInputSubsystem, EnhancedInputAction)
			       : CommonUI::GetIconForInputActions(CommonInputSubsystem, InputActions);
	}*/

	return *FStyleDefaults::GetNoBrush();
}

/*UCommonInputSubsystem* UActionChanger::GetInputSubsystem() const
{
	return UCommonInputSubsystem::Get(GetOwningLocalPlayer());
}*/
