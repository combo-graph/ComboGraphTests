// Copyright 2021 Mickael Daniel. All Rights Reserved.


#include "Abilities/ComboGraphTestAbilitySystemCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemTestAttributeSet.h"

FName AComboGraphTestAbilitySystemCharacter::AbilitySystemComponentName(TEXT("AbilitySystemComponent_Test0"));

AComboGraphTestAbilitySystemCharacter::AComboGraphTestAbilitySystemCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(AbilitySystemComponentName);
	AbilitySystemComponent->SetIsReplicated(true);
}

UAbilitySystemComponent* AComboGraphTestAbilitySystemCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AComboGraphTestAbilitySystemCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	AbilitySystemComponent->InitStats(UAbilitySystemTestAttributeSet::StaticClass(), NULL);
}
