// Copyright 2022 Mickael Daniel. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "ComboGraphTestAbilityAsync.generated.h"

class UAbilitySystemComponent;

/**
 *	AbilityAsync is a base class for ability-specific BlueprintAsyncActions.
 *
 *  These are similar to ability tasks, but they can be executed from any blueprint like an actor and are not tied to a specific ability lifespan.
 *
 *  Backported here from 4.27 since UAbilityAsync is not available in 4.26 and we need it for functional test maps.
 */

UCLASS(Abstract, meta = (ExposedAsyncProxy = AsyncAction))
class COMBOGRAPHTESTS_API UComboGraphTestAbilityAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	/** Explicitly end the action, will disable any callbacks and allow action to be deleted */
	UFUNCTION(BlueprintCallable, Category = "Ability|Async")
	virtual void EndAction();

	/** This should be called prior to broadcasting delegates back into the event graph, this ensures action is still valid */
	virtual bool ShouldBroadcastDelegates() const;

	/** Returns the ability system component this action is bound to */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	/** Sets the bound component, returns true on success */
	virtual void SetAbilitySystemComponent(UAbilitySystemComponent* InAbilitySystemComponent);

	/** Sets the bound component by searching actor, returns true on success */
	virtual void SetAbilityActor(AActor* InActor);

private:
	TWeakObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

};
