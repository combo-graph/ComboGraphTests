// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ComboGraphTestStaminaSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class COMBOGRAPHTESTS_API UComboGraphTestStaminaSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UComboGraphTestStaminaSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(BlueprintReadOnly, Category = "Stamina Attribute Set", ReplicatedUsing = OnRep_Stamina)
    FGameplayAttributeData Stamina = 0.0;
    ATTRIBUTE_ACCESSORS(UComboGraphTestStaminaSet, Stamina)

	UPROPERTY(BlueprintReadOnly, Category = "Stamina Attribute Set", ReplicatedUsing = OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina = 0.0f;
	ATTRIBUTE_ACCESSORS(UComboGraphTestStaminaSet, MaxStamina)

	// Damage is a meta attribute used to calculate final damage, which then turns into -Stamina
	// Temporary value that only exists on the Server. Not replicated.
	UPROPERTY(BlueprintReadOnly, Category = "Stamina Attribute Set", meta = (HideFromLevelInfos))
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UComboGraphTestStaminaSet, Damage)

protected:

    UFUNCTION()
    virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);

	UFUNCTION()
	virtual void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina);
};
