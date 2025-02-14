// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/Character.h"
#include "ComboGraphTestAbilitySystemCharacter.generated.h"

class UGameplayAbility;
class UInputMappingContext;
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
	UPROPERTY(EditDefaultsOnly, Category = "Combo Graph|Test", meta = (RequiredAssetDataTags = "RowStructure=/Script/GameplayAbilities.AttributeMetaData"))
	TSoftObjectPtr<UDataTable> AttributesDataTable;

	/** Input mapping to add to the input system */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Controls")
	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

	UFUNCTION(BlueprintImplementableEvent, Category="Combo Graph|Test")
	void OnAttributeChange(FGameplayAttribute Attribute, const FString& AttributeName, float NewValue, float OldValue, float Delta, const struct FGameplayTagContainer SourceTags);

	/** Priority to bind mapping context with */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Controls")
	int MappingContextPriority = 0;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PostInitializeComponents() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void GrantDefaultAttributes();

	virtual void BeginPlay() override;
	FSimpleDelegate OnBeginPlay;

	virtual void PawnClientRestart() override;
	virtual void PossessedBy(AController* NewController) override;

protected:
	void ReceiveAttributeChange(const FOnAttributeChangeData& OnAttributeChangeData);

private:
	/** Default ASC */
	UPROPERTY(Category = AbilitySystem, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
