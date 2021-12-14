// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpec.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ComboGraphTestFunctionLibrary.generated.h"

class UGameplayAbility;
/**
 *
 */
UCLASS()
class COMBOGRAPHTESTS_API UComboGraphTestFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Grants Ability. Returns handle that can be used in TryActivateAbility, etc. */
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Combo Graph|Testing")
	static FGameplayAbilitySpecHandle GrantAbilityForActor(AActor* Actor, TSubclassOf<UGameplayAbility> Ability, bool bRemoveAfterActivation);

	/** Initializes starting attributes from a data table. */
	UFUNCTION(BlueprintCallable, Category = "Combo Graph|Testing")
	void GrantAndInitAttributesForActor(AActor* Actor, TSubclassOf<class UAttributeSet> Attributes, const UDataTable* DataTable);
};
