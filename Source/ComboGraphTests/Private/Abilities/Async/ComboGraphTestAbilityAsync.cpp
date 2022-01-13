// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Async/ComboGraphTestAbilityAsync.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"

void UComboGraphTestAbilityAsync::EndAction()
{
	// Clear our ASC so it won't broadcast delegates
	SetAbilitySystemComponent(nullptr);
	SetReadyToDestroy();
}

bool UComboGraphTestAbilityAsync::ShouldBroadcastDelegates() const
{
	// By default, broadcast if our ASC is valid
	if (GetAbilitySystemComponent() != nullptr)
	{
		return true;
	}

	return false;
}

UAbilitySystemComponent* UComboGraphTestAbilityAsync::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

void UComboGraphTestAbilityAsync::SetAbilitySystemComponent(UAbilitySystemComponent* InAbilitySystemComponent)
{
	AbilitySystemComponent = InAbilitySystemComponent;
}

void UComboGraphTestAbilityAsync::SetAbilityActor(AActor* InActor)
{
	AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(InActor, true);
}
