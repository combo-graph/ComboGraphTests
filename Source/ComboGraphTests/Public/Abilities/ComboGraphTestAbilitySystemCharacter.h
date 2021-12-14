// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "ComboGraphTestAbilitySystemCharacter.generated.h"

UCLASS()
class COMBOGRAPHTESTS_API AComboGraphTestAbilitySystemCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AComboGraphTestAbilitySystemCharacter(const FObjectInitializer& ObjectInitializer);

	static FName AbilitySystemComponentName;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PostInitializeComponents() override;

private:
	/** DefaultPawn collision component */
	UPROPERTY(Category = AbilitySystem, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent;
};
