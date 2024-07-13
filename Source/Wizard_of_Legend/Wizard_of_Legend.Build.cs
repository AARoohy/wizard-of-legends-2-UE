// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Wizard_of_Legend : ModuleRules
{
	public Wizard_of_Legend(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
