// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct COMBOGRAPHTESTS_API FComboGraphTestNativeTags : public FGameplayTagNativeAdder
{
	FGameplayTag GraphStarted;
	FGameplayTag GraphEnded;
	FGameplayTag GraphStateChanged;
	
	FGameplayTag EventMontageHit;
	FGameplayTag SetByCallerDamage;
	
	FGameplayTag AbilityMeleeCombo;

	FORCEINLINE static const FComboGraphTestNativeTags& Get() { return NativeTags; }

	virtual void AddTags() override
	{
		UGameplayTagsManager& Manager = UGameplayTagsManager::Get();

		GraphStarted = Manager.AddNativeGameplayTag(TEXT("ComboGraphTest.Event.GraphStarted"));
		GraphEnded = Manager.AddNativeGameplayTag(TEXT("ComboGraphTest.Event.GraphEnded"));
		GraphStateChanged = Manager.AddNativeGameplayTag(TEXT("ComboGraphTest.Event.GraphStateChanged"));
		
		EventMontageHit = Manager.AddNativeGameplayTag(TEXT("ComboGraphTest.Event.Montage.Hit"));
		
		SetByCallerDamage = Manager.AddNativeGameplayTag(TEXT("SetByCaller.ComboGraphTest.Damage"));
		
		AbilityMeleeCombo = Manager.AddNativeGameplayTag(TEXT("ComboGraphTest.Ability.Melee.Combo"));
	}

private:

	static FComboGraphTestNativeTags NativeTags;
};
