// Copyright 2021 Mickael Daniel. All Rights Reserved.


#include "Abilities/ComboGraphTestAbilitySystemCharacter.h"

#include "AbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"

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
