// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "ComboGraphTestAbilitySystemCharacter.generated.h"

class UDataTable;
class UAttributeSet;

UCLASS()
class COMBOGRAPHTESTS_API AComboGraphTestAbilitySystemCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AComboGraphTestAbilitySystemCharacter(const FObjectInitializer& ObjectInitializer);

	static FName AbilitySystemComponentName;

	/** List of attributes to grant and initialize */
	UPROPERTY(EditDefaultsOnly, Category="Combo Graph|Test")
	TArray<TSubclassOf<UAttributeSet>> GrantedAttributes;

	/** Datatable to use to initialize base value of granted attributes */
	UPROPERTY(EditDefaultsOnly, Category = "Combo Graph|Test", meta = (RequiredAssetDataTags = "RowStructure=AttributeMetaData"))
	TSoftObjectPtr<UDataTable> AttributesDataTable;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PostInitializeComponents() override;

	virtual void GrantDefaultAttributes();

private:
	/** Default ASC */
	UPROPERTY(Category = AbilitySystem, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* AbilitySystemComponent;
};
