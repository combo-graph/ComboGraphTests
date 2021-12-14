// Copyright 2021 Mickael Daniel. All Rights Reserved.


#include "Utils/ComboGraphTestFunctionLibrary.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"

FGameplayAbilitySpecHandle UComboGraphTestFunctionLibrary::GrantAbilityForActor(AActor* Actor, const TSubclassOf<UGameplayAbility> Ability, const bool bRemoveAfterActivation)
{
	UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor, true);
	FGameplayAbilitySpecHandle AbilityHandle;

	if (ASC)
	{
		if (!ASC->IsOwnerActorAuthoritative())
		{
			return AbilityHandle;
		}

		if (Ability)
		{
			FGameplayAbilitySpec AbilitySpec(Ability);
			AbilitySpec.RemoveAfterActivation = bRemoveAfterActivation;
			AbilityHandle = ASC->GiveAbility(AbilitySpec);
		}
	}

	return AbilityHandle;
}

const UAttributeSet* UComboGraphTestFunctionLibrary::GrantAndInitAttributesForActor(AActor* Actor, TSubclassOf<UAttributeSet> Attributes, const UDataTable* DataTable)
{
	UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor, true);
	if (ASC)
	{
		return ASC->InitStats(Attributes, DataTable);
	}

	return nullptr;
}
