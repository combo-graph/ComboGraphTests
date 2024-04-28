// Copyright 2022 Mickael Daniel. All Rights Reserved.


#include "Abilities/Async/ComboGraphAbilityAsync_WaitAttributesChange.h"

#include "AbilitySystemComponent.h"
#include "ComboGraphTestsLog.h"

UComboGraphAbilityAsync_WaitAttributesChange* UComboGraphAbilityAsync_WaitAttributesChange::WaitAttributesChangeForActor(AActor* TargetActor, TArray<FGameplayAttribute> Attributes)
{
	UComboGraphAbilityAsync_WaitAttributesChange* AsyncAction = NewObject<UComboGraphAbilityAsync_WaitAttributesChange>();
	if (AsyncAction)
	{
		AsyncAction->SetAbilityActor(TargetActor);
		AsyncAction->Attributes = Attributes;
	}
	return AsyncAction;
}

void UComboGraphAbilityAsync_WaitAttributesChange::Activate()
{
	Super::Activate();

	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (ASC)
	{
		for (const FGameplayAttribute& Attribute : Attributes)
		{
			ASC->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(this, &UComboGraphAbilityAsync_WaitAttributesChange::OnAttributeChange);
		}
	}
	else
	{
		EndAction();
	}
}

void UComboGraphAbilityAsync_WaitAttributesChange::EndAction()
{
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (ASC)
	{
		for (const FGameplayAttribute& Attribute : Attributes)
		{
			ASC->GetGameplayAttributeValueChangeDelegate(Attribute).RemoveAll(this);
		}
	}

	Super::EndAction();
}

void UComboGraphAbilityAsync_WaitAttributesChange::OnAttributeChange(const FOnAttributeChangeData& OnAttributeChangeData) const
{
	const FGameplayAttribute GameplayAttribute = OnAttributeChangeData.Attribute;
	const float NewValue = OnAttributeChangeData.NewValue;
	const float OldValue = OnAttributeChangeData.OldValue;
	const float Delta = OldValue - NewValue;

	TESTS_LOG(Verbose, TEXT("=> OnAttributeChange %s New: %f Old: %f - (Delta: %f)"), *GameplayAttribute.GetName(), NewValue, OldValue, Delta)
	AttributeChanged.Broadcast(GameplayAttribute, NewValue, OldValue, Delta);
}
