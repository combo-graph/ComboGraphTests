// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class ComboGraphTests : ModuleRules
{
	public ComboGraphTests(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"GameplayAbilities",
				"GameplayTags",
				"GameplayTasks",
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"ComboGraph",
				"CoreUObject",
				"Engine",
				"EnhancedInput",
				"Slate",
				"SlateCore",
			}
		);
	}
}