// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TPCPP : ModuleRules
{
	public TPCPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
