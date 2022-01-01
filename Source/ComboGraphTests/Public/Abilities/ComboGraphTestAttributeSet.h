// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ComboGraphTestAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class COMBOGRAPHTESTS_API UComboGraphTestAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UComboGraphTestAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(BlueprintReadOnly, Category = "Health Attribute Set", ReplicatedUsing = OnRep_Health)
    FGameplayAttributeData Health = 0.0;
    ATTRIBUTE_ACCESSORS(UComboGraphTestAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category = "Health Attribute Set", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth = 0.0f;
	ATTRIBUTE_ACCESSORS(UComboGraphTestAttributeSet, MaxHealth)


	// Damage is a meta attribute used to calculate final damage, which then turns into -Health
	// Temporary value that only exists on the Server. Not replicated.
	UPROPERTY(BlueprintReadOnly, Category = "Health Attribute Set", meta = (HideFromLevelInfos))
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UComboGraphTestAttributeSet, Damage)

protected:

    UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
};
