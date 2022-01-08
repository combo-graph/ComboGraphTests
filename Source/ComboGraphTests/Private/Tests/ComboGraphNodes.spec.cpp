// Copyright 2021 Mickael Daniel. All Rights Reserved.

#include "ComboGraphTestsLog.h"
#include "Abilities/ComboGraphTestAbilitySystemCharacter.h"
#include "Abilities/ComboGraphTestStaminaSet.h"
#include "Graph/ComboGraph.h"
#include "Graph/ComboGraphNodeAnimBase.h"

BEGIN_DEFINE_SPEC(FComboGraphNodesSpec, "ComboGraph.Nodes", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	UWorld* World;

	UComboGraph* ComboGraph;
	UComboGraphNodeAnimBase* Node;

	AComboGraphTestAbilitySystemCharacter* SourceActor;
	UAbilitySystemComponent* SourceASC;

	AComboGraphTestAbilitySystemCharacter* TargetActor;
	UAbilitySystemComponent* TargetASC;

	uint64 InitialFrameCounter = 0;

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
END_DEFINE_SPEC(FComboGraphNodesSpec)

void FComboGraphNodesSpec::Define()
{
	Describe("ComboGraph Nodes API", [this]()
	{
		BeforeEach([this]()
		{
			// Setup tests
			// CreateAndSetupWorld();

			ComboGraph = Cast<UComboGraph>(StaticLoadObject(UComboGraph::StaticClass(), nullptr, TEXT("/ComboGraphTests/Fixtures/CG_Test_Fixture.CG_Test_Fixture")));
		});

		It("ComboGraph should be created", [this]()
		{
			TestTrue("ComboGraph is valid", ComboGraph != nullptr);
		});

		It("ComboGraph.EntryNode is created", [this]()
		{
			check(ComboGraph)
			TestTrue("EntryNode", ComboGraph->EntryNode != nullptr);
		});

		It("ComboGraph.FirstNode is created", [this]()
		{
			check(ComboGraph)
			TestTrue("EntryNode", ComboGraph->FirstNode != nullptr);
		});

		Describe("UComboGraphNodeAnimBase", [this]()
		{
			BeforeEach([this]()
			{
				check(ComboGraph);
				Node = Cast<UComboGraphNodeAnimBase>(ComboGraph->FirstNode);
			});

			It("first node should be anim based", [this]()
			{
				TestTrue("first node is anim based", Node != nullptr);
			});

			It("GetNodeTitle()", [this]()
			{
				const FString NodeTitle = Node->K2_GetNodeTitle().ToString();
				TestEqual("Node title is correct", NodeTitle, "Melee_A");
			});

			It("GetAnimationAsset()", [this]()
			{
				const UAnimationAsset* Asset = Node->K2_GetAnimationAsset();
				TestEqual("Asset name", Asset->GetName(), "Melee_A");
				TestEqual("Asset name", Asset->GetName(), Node->GetNodeTitle().ToString());
			});

			It("GetAnimationClass()", [this]()
			{
				TestEqual("Asset Class is a Sequence", Node->K2_GetAnimationClass(), UAnimSequence::StaticClass());
			});

			It("GetChildren()", [this]()
			{
				TestEqual("child num", Node->K2_GetChildren().Num(), 1);
			});

			It("GetOwningGraph()", [this]()
			{
				TestEqual("owning graph", Node->K2_GetOwningGraph(), ComboGraph);
			});
		});

		AfterEach([this]()
		{
			// TeardownWorld();
		});
	});
}
