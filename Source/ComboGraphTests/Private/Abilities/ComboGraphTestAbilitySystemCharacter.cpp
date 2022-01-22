// Copyright 2021 Mickael Daniel. All Rights Reserved.


#include "Abilities/ComboGraphTestAbilitySystemCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"

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

	check(AbilitySystemComponent);

	GrantDefaultAttributes();


	TArray<FGameplayAttribute> Attributes;
	AbilitySystemComponent->GetAllAttributes(Attributes);
	for (FGameplayAttribute Attribute : Attributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(this, &AComboGraphTestAbilitySystemCharacter::ReceiveAttributeChange);
	}

}

void AComboGraphTestAbilitySystemCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (AbilitySystemComponent)
	{
		TArray<FGameplayAttribute> Attributes;
		AbilitySystemComponent->GetAllAttributes(Attributes);

		for (const FGameplayAttribute Attribute : Attributes)
		{
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).RemoveAll(this);
		}
	}

	Super::EndPlay(EndPlayReason);
}

void AComboGraphTestAbilitySystemCharacter::GrantDefaultAttributes()
{
	// Load data table soft object if valid
	const UDataTable* InitDataTable = nullptr;
	if (!AttributesDataTable.IsNull())
	{
		UDataTable* DataTable = AttributesDataTable.LoadSynchronous();
		if (DataTable)
		{
			InitDataTable = DataTable;
		}
	}

	// Grant attributes and initialize with data table if it was found (can be nullptr)
	for (const TSubclassOf<UAttributeSet> GrantedAttribute : GrantedAttributes)
	{
		AbilitySystemComponent->InitStats(GrantedAttribute, InitDataTable);
	}
}

void AComboGraphTestAbilitySystemCharacter::BeginPlay()
{
	Super::BeginPlay();
	OnBeginPlay.ExecuteIfBound();
}

void AComboGraphTestAbilitySystemCharacter::PawnClientRestart()
{
	Super::PawnClientRestart();
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

void AComboGraphTestAbilitySystemCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

void AComboGraphTestAbilitySystemCharacter::ReceiveAttributeChange(const FOnAttributeChangeData& OnAttributeChangeData)
{
	const float NewValue = OnAttributeChangeData.NewValue;
	const float OldValue = OnAttributeChangeData.OldValue;

	// Prevent broadcast Attribute changes if New and Old values are the same
	// most likely because of clamping in post gameplay effect execute
	if (OldValue == NewValue)
	{
		return;
	}

	const FGameplayEffectModCallbackData* ModData = OnAttributeChangeData.GEModData;
	FGameplayTagContainer SourceTags = FGameplayTagContainer();
	if (ModData)
	{
		SourceTags = *ModData->EffectSpec.CapturedSourceTags.GetAggregatedTags();
	}

	// Broadcast attribute change to component
	OnAttributeChange(OnAttributeChangeData.Attribute, OnAttributeChangeData.Attribute.GetName(), NewValue, OldValue, NewValue - OldValue, SourceTags);
}
