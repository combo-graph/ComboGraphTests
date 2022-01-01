// Copyright 2021 Mickael Daniel. All Rights Reserved.


#include "Abilities/ComboGraphTestAbilitySystemCharacter.h"
#include "Abilities/ComboGraphTestAttributeSet.h"

BEGIN_DEFINE_SPEC(FComboGraphSpec, "ComboGraph.Sanity", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	UWorld* World;

	AComboGraphTestAbilitySystemCharacter* SourceActor;
	UAbilitySystemComponent* SourceASC;

	AComboGraphTestAbilitySystemCharacter* TargetActor;
	UAbilitySystemComponent* TargetASC;

	uint64 InitialFrameCounter = 0;

	UDataTable* FComboGraphSpec::CreateAttributesDataTable()
	{
		FString CSV(TEXT("---,BaseValue,MinValue,MaxValue,DerivedAttributeInfo,bCanStack"));
		CSV.Append(TEXT("\r\nComboGraphTestAttributeSet.MaxHealth,\"500.000000\",\"0.000000\",\"1.000000\",\"\",\"False\""));
		CSV.Append(TEXT("\r\nComboGraphTestAttributeSet.Health,\"500.000000\",\"0.000000\",\"1.000000\",\"\",\"False\""));

		UDataTable* DataTable = NewObject<UDataTable>(GetTransientPackage(), FName(TEXT("TempDataTable")));
		DataTable->RowStruct = FAttributeMetaData::StaticStruct();
		DataTable->CreateTableFromCSVString(CSV);

		const FAttributeMetaData* Row = (const FAttributeMetaData*)DataTable->GetRowMap()["ComboGraphTestAttributeSet.MaxHealth"];
		if (Row)
		{
			check(Row->BaseValue == 500.f);
		}
		return DataTable;
	}
END_DEFINE_SPEC(FComboGraphSpec)

void FComboGraphSpec::Define()
{
	BeforeEach([this]()
	{
		// Setup tests
		World = UWorld::CreateWorld(EWorldType::Game, false);
		FWorldContext& WorldContext = GEngine->CreateNewWorldContext(EWorldType::Game);
		WorldContext.SetCurrentWorld(World);

		FURL URL;
		World->InitializeActorsForPlay(URL);
		World->BeginPlay();

		InitialFrameCounter = GFrameCounter;

		// set up the source actor
		SourceActor = World->SpawnActor<AComboGraphTestAbilitySystemCharacter>();
		SourceASC = SourceActor->GetAbilitySystemComponent();
		SourceActor->GrantedAttributes.Add(UComboGraphTestAttributeSet::StaticClass());
		SourceActor->AttributesDataTable = CreateAttributesDataTable();
		SourceActor->GrantDefaultAttributes();

		// set up the destination actor
		TargetActor = World->SpawnActor<AComboGraphTestAbilitySystemCharacter>();
		TargetASC = TargetActor->GetAbilitySystemComponent();
		TargetActor->GrantedAttributes.Add(UComboGraphTestAttributeSet::StaticClass());
		TargetActor->AttributesDataTable = CreateAttributesDataTable();
		TargetActor->GrantDefaultAttributes();
	});

	It("should have attributes initialized", [this]()
	{
		TestTrue("Source ASC has UComboGraphTestAttributeSet granted", SourceASC->HasAttributeSetForAttribute(UComboGraphTestAttributeSet::GetHealthAttribute()));
		TestTrue("Target ASC has UComboGraphTestAttributeSet granted", TargetASC->HasAttributeSetForAttribute(UComboGraphTestAttributeSet::GetHealthAttribute()));

		TestEqual("Source ASC AttributeSet Health is initialized to 500.f", SourceASC->GetNumericAttributeBase(UComboGraphTestAttributeSet::GetHealthAttribute()), 500.f);
		TestEqual("Target ASC AttributeSet Health is initialized to 500.f", TargetASC->GetNumericAttributeBase(UComboGraphTestAttributeSet::GetHealthAttribute()), 500.f);
	});

	AfterEach([this]()
	{
		GFrameCounter = InitialFrameCounter;

		GEngine->DestroyWorldContext(World);
		World->DestroyWorld(false);
	});

}
