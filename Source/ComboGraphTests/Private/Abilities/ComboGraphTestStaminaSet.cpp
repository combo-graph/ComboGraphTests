// Copyright 2021 Mickael Daniel. All Rights Reserved.


#include "Abilities/ComboGraphTestStaminaSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

// Sets default values
UComboGraphTestStaminaSet::UComboGraphTestStaminaSet()
{
	// Default constructor
}

void UComboGraphTestStaminaSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // This is called whenever attributes change, so for max attributes we want to scale the current totals to match
    Super::PreAttributeChange(Attribute, NewValue);
}

void UComboGraphTestStaminaSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		// Store a local copy of the amount of Damage done and clear the Damage attribute.
		const float LocalDamageDone = GetDamage();
		SetDamage(0.f);

		if (LocalDamageDone > 0.f)
		{
			// Apply the Stamina change and then clamp it.
			const float NewStamina = GetStamina() - LocalDamageDone;
			SetStamina(FMath::Clamp(NewStamina, 0.f, GetMaxStamina()));
		}
	}
	else if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		// Clamp Stamina
		SetStamina(FMath::Clamp(GetStamina(), 0.f, GetMaxStamina()));
	}
}

void UComboGraphTestStaminaSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UComboGraphTestStaminaSet, Stamina, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UComboGraphTestStaminaSet, MaxStamina, COND_None, REPNOTIFY_Always);
}

void UComboGraphTestStaminaSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UComboGraphTestStaminaSet, Stamina, OldStamina);
}

void UComboGraphTestStaminaSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UComboGraphTestStaminaSet, MaxStamina, OldMaxStamina);
}
