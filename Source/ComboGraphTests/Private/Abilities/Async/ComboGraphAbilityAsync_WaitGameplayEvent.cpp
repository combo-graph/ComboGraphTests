// Copyright 2022 Mickael Daniel. All Rights Reserved.

#include "Abilities/Async/ComboGraphAbilityAsync_WaitGameplayEvent.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"

UComboGraphAbilityAsync_WaitGameplayEvent* UComboGraphAbilityAsync_WaitGameplayEvent::WaitGameplayEventToActorForComboGraphTesting(AActor* TargetActor, FGameplayTag EventTag, bool OnlyTriggerOnce, bool OnlyMatchExact)
{
	UComboGraphAbilityAsync_WaitGameplayEvent* AsyncAction = NewObject<UComboGraphAbilityAsync_WaitGameplayEvent>();
	if (AsyncAction)
	{
		AsyncAction->SetAbilityActor(TargetActor);
		AsyncAction->Tag = EventTag;
		AsyncAction->OnlyTriggerOnce = OnlyTriggerOnce;
		AsyncAction->OnlyMatchExact = OnlyMatchExact;
	}
	return AsyncAction;
}

void UComboGraphAbilityAsync_WaitGameplayEvent::Activate()
{
	Super::Activate();

	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (ASC)
	{
		if (OnlyMatchExact)
		{
			MyHandle = ASC->GenericGameplayEventCallbacks.FindOrAdd(Tag).AddUObject(this, &UComboGraphAbilityAsync_WaitGameplayEvent::GameplayEventCallback);
		}
		else
		{
			MyHandle = ASC->AddGameplayEventTagContainerDelegate(FGameplayTagContainer(Tag), FGameplayEventTagMulticastDelegate::FDelegate::CreateUObject(this, &UComboGraphAbilityAsync_WaitGameplayEvent::GameplayEventContainerCallback));
		}
	}
	else
	{
		EndAction();
	}
}

void UComboGraphAbilityAsync_WaitGameplayEvent::GameplayEventCallback(const FGameplayEventData* Payload)
{
	GameplayEventContainerCallback(Tag, Payload);
}

void UComboGraphAbilityAsync_WaitGameplayEvent::GameplayEventContainerCallback(FGameplayTag MatchingTag, const FGameplayEventData* Payload)
{
	if (ShouldBroadcastDelegates())
	{
		FGameplayEventData TempPayload = *Payload;
		TempPayload.EventTag = MatchingTag;
		EventReceived.Broadcast(MoveTemp(TempPayload));

		if (OnlyTriggerOnce)
		{
			EndAction();
		}
	}
	else
	{
		EndAction();
	}
}

void UComboGraphAbilityAsync_WaitGameplayEvent::EndAction()
{
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (ASC && MyHandle.IsValid())
	{
		if (OnlyMatchExact)
		{
			ASC->GenericGameplayEventCallbacks.FindOrAdd(Tag).Remove(MyHandle);
		}
		else
		{
			ASC->RemoveGameplayEventTagContainerDelegate(FGameplayTagContainer(Tag), MyHandle);
		}

	}
	Super::EndAction();
}
