// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct COMBOGRAPHTESTS_API FComboGraphTestNativeTags : public FGameplayTagNativeAdder
{
	FGameplayTag ComboTestGraphBegin;
	FGameplayTag ComboTestGraphEnd;
	FGameplayTag ComboTestGraphStateChange;

	FORCEINLINE static const FComboGraphTestNativeTags& Get() { return NativeTags; }

	virtual void AddTags() override
	{
		UGameplayTagsManager& Manager = UGameplayTagsManager::Get();

		ComboTestGraphBegin = Manager.AddNativeGameplayTag(TEXT("ComboGraphTest.Event.GraphStarted"));
		ComboTestGraphEnd = Manager.AddNativeGameplayTag(TEXT("ComboGraphTest.Event.GraphEnded"));
		ComboTestGraphStateChange = Manager.AddNativeGameplayTag(TEXT("ComboGraphTest.Event.GraphStateChanged"));
		ComboTestGraphStateChange = Manager.AddNativeGameplayTag(TEXT("ComboGraphTest.Event.Montage.Hit"));
		ComboTestGraphStateChange = Manager.AddNativeGameplayTag(TEXT("SetByCaller.ComboGraphTest.Damage"));
	}

private:

	static FComboGraphTestNativeTags NativeTags;
};
