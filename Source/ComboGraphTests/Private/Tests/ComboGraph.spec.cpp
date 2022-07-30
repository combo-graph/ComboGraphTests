// Copyright 2021 Mickael Daniel. All Rights Reserved.

#include "ComboGraphTestsLog.h"
#include "Abilities/ComboGraphTestAbilitySystemCharacter.h"
#include "Abilities/ComboGraphTestHealthSet.h"
#include "Abilities/ComboGraphTestNativeTags.h"
#include "Abilities/ComboGraphTestStaminaSet.h"

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

	void Test(UGameplayAbility* Ability) {}

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
			// Setup tests
			CreateAndSetupWorld();

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
			TestEqual("Source ASC AttributeSet Stamina is initialized to 100.f", SourceASC->GetNumericAttributeBase(UComboGraphTestStaminaSet::GetStaminaAttribute()), 100.f);

			SourceActor->DispatchBeginPlay();

			const TArray<FGameplayAbilitySpec> ActivatableAbilities = SourceASC->GetActivatableAbilities();
			TestEqual("Number of abilities granted is 2", ActivatableAbilities.Num(), 2);

			const bool bSuccess = SourceASC->TryActivateAbilityByClass(AbilityType);
			TestTrue("Ability was activated", bSuccess);

			World->GetTimerManager().SetTimerForNextTick([this, Done]()
			{
				TestEqual("Source ASC AttributeSet Stamina is expected to be 90.f now", SourceASC->GetNumericAttributeBase(UComboGraphTestStaminaSet::GetStaminaAttribute()), 90.f);
				Done.Execute();
			});

			// Tick world a little so that timer is processed
			TickWorld(0.1f);
		});

		AfterEach([this]()
		{
			TeardownWorld();
		});
	});
}
