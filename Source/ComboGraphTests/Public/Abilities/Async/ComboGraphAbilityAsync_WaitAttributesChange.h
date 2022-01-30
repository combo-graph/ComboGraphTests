// Copyright 2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ComboGraphTestAbilityAsync.h"
#include "ComboGraphAbilityAsync_WaitAttributesChange.generated.h"

UCLASS(BlueprintType)
class COMBOGRAPHTESTS_API UComboGraphAbilityAsync_WaitAttributesChange : public UComboGraphTestAbilityAsync
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FAttributeChangedDelegate, FGameplayAttribute, Attribute, float, NewValue, float, OldValue, float, Delta);

public:

	/**
	 * Wait for attribute changes on the target ASC for the passed in Actor (if it has an ASC)
	 */
	UFUNCTION(BlueprintCallable, Category = "Ability|Async", meta = (DefaultToSelf = "TargetActor", DisplayName = "Wait for Attributes Change (Combo Graph Testing)", BlueprintInternalUseOnly = "TRUE"))
	static UComboGraphAbilityAsync_WaitAttributesChange* WaitAttributesChangeForActor(AActor* TargetActor, TArray<FGameplayAttribute> Attributes);

	UPROPERTY(BlueprintAssignable)
	FAttributeChangedDelegate AttributeChanged;

protected:

	TArray<FGameplayAttribute> Attributes;

	virtual void Activate() override;
	virtual void EndAction() override;

	void OnAttributeChange(const FOnAttributeChangeData& OnAttributeChangeData) const;
};
