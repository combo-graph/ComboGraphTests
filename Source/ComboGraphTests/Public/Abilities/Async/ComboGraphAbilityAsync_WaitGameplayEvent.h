// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "ComboGraphTestAbilityAsync.h"
#include "GameplayEffectTypes.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "ComboGraphAbilityAsync_WaitGameplayEvent.generated.h"

class UAbilitySystemComponent;

UCLASS()
class COMBOGRAPHTESTS_API UComboGraphAbilityAsync_WaitGameplayEvent : public UComboGraphTestAbilityAsync
{
	GENERATED_BODY()

public:
	/**
	 * Wait until the specified gameplay tag event is triggered on a target ability system component
	 * It will keep listening as long as OnlyTriggerOnce = false
	 * If OnlyMatchExact = false it will trigger for nested tags
	 */
	UFUNCTION(BlueprintCallable, Category = "Ability|Async", meta = (DefaultToSelf = "TargetActor", BlueprintInternalUseOnly = "TRUE"))
	static UComboGraphAbilityAsync_WaitGameplayEvent* WaitGameplayEventToActorForComboGraphTesting(AActor* TargetActor, FGameplayTag EventTag, bool OnlyTriggerOnce = false, bool OnlyMatchExact = true);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventReceivedDelegate, FGameplayEventData, Payload);

	UPROPERTY(BlueprintAssignable)
	FEventReceivedDelegate EventReceived;

protected:
	virtual void Activate() override;
	virtual void EndAction() override;

	virtual void GameplayEventCallback(const FGameplayEventData* Payload);
	virtual void GameplayEventContainerCallback(FGameplayTag MatchingTag, const FGameplayEventData* Payload);

	FGameplayTag Tag;
	bool OnlyTriggerOnce = false;
	bool OnlyMatchExact = false;

	FDelegateHandle MyHandle;
};
