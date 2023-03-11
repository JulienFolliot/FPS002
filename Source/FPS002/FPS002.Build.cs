// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FPS002 : ModuleRules
{
	public FPS002(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
