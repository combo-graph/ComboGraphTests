// Copyright 2021 Mickael Daniel. All Rights Reserved.


#include "Abilities/ComboGraphTestHealthSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

// Sets default values
UComboGraphTestHealthSet::UComboGraphTestHealthSet()
{
	// Default constructor
}

void UComboGraphTestHealthSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // This is called whenever attributes change, so for max attributes we want to scale the current totals to match
    Super::PreAttributeChange(Attribute, NewValue);
}

void UComboGraphTestHealthSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		// Store a local copy of the amount of Damage done and clear the Damage attribute.
		const float LocalDamageDone = GetDamage();
		SetDamage(0.f);

		if (LocalDamageDone > 0.f)
		{
			// Apply the Health change and then clamp it.
			const float NewHealth = GetHealth() - LocalDamageDone;
			SetHealth(FMath::Clamp(NewHealth, 0.f, GetMaxHealth()));
		}
	}
	else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		// Clamp Health
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
}

void UComboGraphTestHealthSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UComboGraphTestHealthSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UComboGraphTestHealthSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UComboGraphTestHealthSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UComboGraphTestHealthSet, Health, OldHealth);
}

void UComboGraphTestHealthSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UComboGraphTestHealthSet, MaxHealth, OldMaxHealth);
}
