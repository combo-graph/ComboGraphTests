// Copyright 2021 Mickael Daniel. All Rights Reserved.

#include "ComboGraphTestsLog.h"
#include "Abilities/ComboGraphTestAbilitySystemCharacter.h"
#include "Abilities/ComboGraphTestHealthSet.h"
#include "Abilities/ComboGraphTestStaminaSet.h"
#include "Misc/AutomationTest.h"

BEGIN_DEFINE_SPEC(FComboGraphSpec, "ComboGraph", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	UWorld* World;

	TSubclassOf<AComboGraphTestAbilitySystemCharacter> ActorType;
	TSubclassOf<UGameplayAbility> AbilityType;

	APlayerController* PlayerController;

	AComboGraphTestAbilitySystemCharacter* SourceActor;
	UAbilitySystemComponent* SourceASC;

	AComboGraphTestAbilitySystemCharacter* TargetActor;
	UAbilitySystemComponent* TargetASC;

	uint64 InitialFrameCounter = 0;

	void DebugInfo(const FString& InMessage)
	{
		UE_LOG(LogComboGraphTests, Display, TEXT("%s"), *InMessage)
		AddInfo(InMessage);
	}

	void CreateAndSetupWorld()
	{
		World = UWorld::CreateWorld(EWorldType::Game, false);
		FWorldContext& WorldContext = GEngine->CreateNewWorldContext(EWorldType::Game);
		WorldContext.SetCurrentWorld(World);

		FURL URL;
		World->InitializeActorsForPlay(URL);
		World->BeginPlay();

		InitialFrameCounter = GFrameCounter;
	}

	void TeardownWorld()
	{
		GFrameCounter = InitialFrameCounter;

#if WITH_EDITOR
		if (GIsEditor)
		{
			World->EditorDestroyActor(SourceActor, /*bShouldModifyLevel*/false);
			World->EditorDestroyActor(TargetActor, /*bShouldModifyLevel*/false);
		}
		else
#endif	// WITH_EDITOR
		{
			World->DestroyActor(SourceActor, /*bNetForce*/false, /*bShouldModifyLevel*/false);
			World->DestroyActor(TargetActor, /*bNetForce*/false, /*bShouldModifyLevel*/false);
		}

		GEngine->DestroyWorldContext(World);
		World->DestroyWorld(false);
	}

	void TickWorld(float Time)
	{
		constexpr float Step = 0.1f;
		while (Time > 0.f)
		{
			World->Tick(ELevelTick::LEVELTICK_All, FMath::Min(Time, Step));
			Time -= Step;

			// This is terrible but required for subticking like this.
			// we could always cache the real GFrameCounter at the start of our tests and restore it when finished.
			GFrameCounter++;
		}
	}

	UDataTable* CreateAttributesDataTable() const
	{
		FString CSV(TEXT("---,BaseValue,MinValue,MaxValue,DerivedAttributeInfo,bCanStack"));
		CSV.Append(TEXT("\r\nComboGraphTestHealthSet.MaxHealth,\"500.000000\",\"0.000000\",\"1.000000\",\"\",\"False\""));
		CSV.Append(TEXT("\r\nComboGraphTestHealthSet.Health,\"500.000000\",\"0.000000\",\"1.000000\",\"\",\"False\""));

		UDataTable* DataTable = NewObject<UDataTable>(GetTransientPackage(), FName(TEXT("TempDataTable")));
		DataTable->RowStruct = FAttributeMetaData::StaticStruct();
		DataTable->CreateTableFromCSVString(CSV);

		const FAttributeMetaData* Row = reinterpret_cast<const FAttributeMetaData*>(DataTable->GetRowMap()["ComboGraphTestHealthSet.MaxHealth"]);
		if (Row)
		{
			check(Row->BaseValue == 500.f);
		}
		return DataTable;
	}

END_DEFINE_SPEC(FComboGraphSpec)

void FComboGraphSpec::Define()
{
	Describe("Basics", [this]()
	{
		BeforeEach([this]()
		{
			DebugInfo(TEXT("Basics: Create and setup world"));

			// Setup tests
			CreateAndSetupWorld();

			// set up the source actor
			SourceActor = World->SpawnActor<AComboGraphTestAbilitySystemCharacter>();
			SourceASC = SourceActor->GetAbilitySystemComponent();
			SourceActor->GrantedAttributes.Add(UComboGraphTestHealthSet::StaticClass());
			SourceActor->AttributesDataTable = CreateAttributesDataTable();
			SourceActor->GrantDefaultAttributes();

			// set up the destination actor
			TargetActor = World->SpawnActor<AComboGraphTestAbilitySystemCharacter>();
			TargetASC = TargetActor->GetAbilitySystemComponent();
			TargetActor->GrantedAttributes.Add(UComboGraphTestHealthSet::StaticClass());
			TargetActor->AttributesDataTable = CreateAttributesDataTable();
			TargetActor->GrantDefaultAttributes();

			DebugInfo(TEXT("Basics: Before Each Done"));
		});

		It("should setup world and such", [this]()
		{
			TestTrue("Source Actor should have been spawned", SourceActor != nullptr);
			TestTrue("Target Actor should have been spawned", TargetActor != nullptr);
			TestTrue("Source Actor ASC should be created", SourceActor->GetAbilitySystemComponent() != nullptr);
			TestTrue("Target Actor ASC should be created", TargetActor->GetAbilitySystemComponent() != nullptr);
		});

		It("should have attributes initialized", [this]()
		{
			TestTrue("Source ASC has UComboGraphTestHealthSet granted", SourceASC->HasAttributeSetForAttribute(UComboGraphTestHealthSet::GetHealthAttribute()));
			TestTrue("Target ASC has UComboGraphTestHealthSet granted", TargetASC->HasAttributeSetForAttribute(UComboGraphTestHealthSet::GetHealthAttribute()));

			TestEqual("Source ASC AttributeSet Health is initialized to 500.f", SourceASC->GetNumericAttributeBase(UComboGraphTestHealthSet::GetHealthAttribute()), 500.f);
			TestEqual("Target ASC AttributeSet Health is initialized to 500.f", TargetASC->GetNumericAttributeBase(UComboGraphTestHealthSet::GetHealthAttribute()), 500.f);
		});

		AfterEach([this]()
		{
			TeardownWorld();
		});
	});

	Describe("Feature Testing", [this]()
	{
		BeforeEach([this]()
		{
			DebugInfo(TEXT("Feature Testing: Create and setup world"));

			// Setup tests
			CreateAndSetupWorld();

			DebugInfo(TEXT("World created"));

			ActorType = StaticLoadClass(AComboGraphTestAbilitySystemCharacter::StaticClass(), nullptr, TEXT("/ComboGraphTests/Fixtures/Characters/BP_Test_AbilitySystemCharacter.BP_Test_AbilitySystemCharacter_C"));
			AbilityType = StaticLoadClass(UGameplayAbility::StaticClass(), nullptr, TEXT("/ComboGraphTests/Fixtures/GA_Combo_TestFixture.GA_Combo_TestFixture_C"));

			// set up the source actor
			SourceActor = CastChecked<AComboGraphTestAbilitySystemCharacter>(World->SpawnActor(ActorType, nullptr, nullptr, FActorSpawnParameters()));
			SourceASC = SourceActor->GetAbilitySystemComponent();

			PlayerController = World->SpawnActor<APlayerController>();
			PlayerController->Possess(SourceActor);


			// set up the destination actor
			TargetActor = CastChecked<AComboGraphTestAbilitySystemCharacter>(World->SpawnActor(ActorType, nullptr, nullptr, FActorSpawnParameters()));
			TargetASC = TargetActor->GetAbilitySystemComponent();

			DebugInfo(TEXT("Feature Testing Before Each Done"));
		});

		It("should setup world and such", [this]()
		{
			TestTrue("Source Actor should have been spawned", SourceActor != nullptr);
			TestTrue("Target Actor should have been spawned", TargetActor != nullptr);
			TestTrue("Source Actor ASC should be created", SourceActor->GetAbilitySystemComponent() != nullptr);
			TestTrue("Target Actor ASC should be created", TargetActor->GetAbilitySystemComponent() != nullptr);
		});

		It("should have attributes initialized", [this]()
		{
			TestTrue("Source ASC has UComboGraphTestHealthSet granted", SourceASC->HasAttributeSetForAttribute(UComboGraphTestHealthSet::GetHealthAttribute()));
			TestTrue("Target ASC has UComboGraphTestHealthSet granted", TargetASC->HasAttributeSetForAttribute(UComboGraphTestHealthSet::GetHealthAttribute()));
			TestTrue("Source ASC has UComboGraphTestStaminaSet granted", SourceASC->HasAttributeSetForAttribute(UComboGraphTestStaminaSet::GetStaminaAttribute()));
			TestTrue("Target ASC has UComboGraphTestStaminaSet granted", TargetASC->HasAttributeSetForAttribute(UComboGraphTestStaminaSet::GetStaminaAttribute()));

			TestEqual("Source ASC AttributeSet Health is initialized to 1000.f", SourceASC->GetNumericAttributeBase(UComboGraphTestHealthSet::GetHealthAttribute()), 1000.f);
			TestEqual("Target ASC AttributeSet Health is initialized to 1000.f", TargetASC->GetNumericAttributeBase(UComboGraphTestHealthSet::GetHealthAttribute()), 1000.f);
			TestEqual("Source ASC AttributeSet Stamina is initialized to 100.f", SourceASC->GetNumericAttributeBase(UComboGraphTestStaminaSet::GetStaminaAttribute()), 100.f);
			TestEqual("Target ASC AttributeSet Stamina is initialized to 100.f", TargetASC->GetNumericAttributeBase(UComboGraphTestStaminaSet::GetStaminaAttribute()), 100.f);
		});

		LatentIt("should decrease stamina on ability activation when playing first montage", [this](const FDoneDelegate& Done)
		{
			// Async task offload on game thread seems to be necessary on 5.3 / 5.4 - likely engine bug. Test without on future engine updates.
			AsyncTask(ENamedThreads::GameThread, [this, Done]()
			{
				FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateLambda([this, Done](float Delta)
				{
					TestEqual("Source ASC AttributeSet Stamina is expected to be 90.f now", SourceASC->GetNumericAttributeBase(UComboGraphTestStaminaSet::GetStaminaAttribute()), 90.f);
					AddInfo(FString::Printf(TEXT("Spec done")));
					Done.Execute();

					return false;
				}), 0.5f);
			});

			TestEqual("Source ASC AttributeSet Stamina is initialized to 100.f", SourceASC->GetNumericAttributeBase(UComboGraphTestStaminaSet::GetStaminaAttribute()), 100.f);

			AddInfo(FString::Printf(TEXT("Dispatch Begin Play")));
			SourceActor->DispatchBeginPlay();

			const TArray<FGameplayAbilitySpec>& ActivatableAbilities = SourceASC->GetActivatableAbilities();
			TestEqual("Number of abilities granted is 1", ActivatableAbilities.Num(), 1);

			// Why was it 2 in 1.4.x ?
			// => because ComboGrapySystem actor component is added to the fixture actors, but fails to load in this 2.x version
			AddInfo(FString::Printf(TEXT("Activatable Abilities: %d"), ActivatableAbilities.Num()));
			for (const FGameplayAbilitySpec& ActivatableAbility : ActivatableAbilities)
			{
				AddInfo(FString::Printf(TEXT("\t Activatable Abilities: %s"), *GetNameSafe(ActivatableAbility.Ability)));
			}

			const bool bSuccess = SourceASC->TryActivateAbilityByClass(AbilityType);

			AddInfo(FString::Printf(TEXT("Ability %s was activated, status: %s"), *GetNameSafe(AbilityType), *LexToString(bSuccess)));
			TestTrue("Ability was activated", bSuccess);

			TickWorld(1.5f);
		});

		xDescribe(TEXT("Laten spec issue debug on 5.3 / 5.4"), [this]()
		{
			// Latent action seems to have issue on 5.3 preview
			LatentIt(TEXT("Latent test - OK"), [this](const FDoneDelegate& Done)
			{
				AddInfo(FString::Printf(TEXT("Definitely wtf")));
				AsyncTask(
					ENamedThreads::GameThread,
					[this, Done]()
					{
						AddInfo(FString::Printf(TEXT("Spec done")));
						Done.Execute();
					}
				);
			});

			LatentIt(TEXT("Latent test - NOK - It does timeout"), [this](const FDoneDelegate& Done)
			{
				AddInfo(FString::Printf(TEXT("Definitely wtf")));
				Done.Execute();
			});

			LatentIt(TEXT("Latent test - OK - It does not timeout"), EAsyncExecution::ThreadPool, [this](const FDoneDelegate& Done)
			{
				AddInfo(FString::Printf(TEXT("Definitely wtf")));
				Done.Execute();
			});
		});

		AfterEach([this]()
		{
			TeardownWorld();
		});
	});
}
