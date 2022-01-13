// Copyright 2021 Mickael Daniel. All Rights Reserved.

#include "ComboGraphTestsLog.h"
#include "Abilities/ComboGraphTestAbilitySystemCharacter.h"
#include "Abilities/ComboGraphTestStaminaSet.h"
#include "Abilities/Tasks/ComboGraphAbilityTask_StartGraph.h"
#include "Graph/ComboGraph.h"
#include "Graph/ComboGraphNodeAnimBase.h"

BEGIN_DEFINE_SPEC(FComboGraphNodesSpec, "ComboGraph.Nodes", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	UWorld* World;

	UComboGraph* ComboGraph;
	UComboGraphNodeAnimBase* Node;
	TSubclassOf<UGameplayAbility> AbilityType;

	AComboGraphTestAbilitySystemCharacter* SourceActor;
	UAbilitySystemComponent* SourceASC;

	AComboGraphTestAbilitySystemCharacter* TargetActor;
	UAbilitySystemComponent* TargetASC;

	uint64 InitialFrameCounter = 0;

	// bool bBeginPlayDispatched = false;

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

		// Wish we had Before() / After() BDD hooks ...

		BeforeEach([this]()
		{
			// Setup tests
			CreateAndSetupWorld();

			UClass* ActorType = StaticLoadClass(AComboGraphTestAbilitySystemCharacter::StaticClass(), nullptr, TEXT("/ComboGraphTests/Fixtures/Characters/BP_ComboTestCharacter.BP_ComboTestCharacter_C"));
			AbilityType = StaticLoadClass(UGameplayAbility::StaticClass(), nullptr, TEXT("/ComboGraphTests/Fixtures/GA_Combo_TestFixture.GA_Combo_TestFixture_C"));

			// set up the source actor
			SourceActor = CastChecked<AComboGraphTestAbilitySystemCharacter>(World->SpawnActor(ActorType, nullptr, nullptr, FActorSpawnParameters()));
			SourceASC = SourceActor->GetAbilitySystemComponent();

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

				if (!SourceActor->HasActorBegunPlay())
				{
					// Make sure ability is granted
					TESTS_LOG(Display, TEXT("DispatchBeginPlay()"))
					SourceActor->DispatchBeginPlay();

					// And activated once, so as to make sure Node is updated with gameplay task owner interface calls
					TESTS_LOG(Display, TEXT("TryActivateAbilityByClass(%s)"), *GetNameSafe(AbilityType))
					SourceASC->TryActivateAbilityByClass(AbilityType);
				}
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

				TArray<UComboGraphNodeAnimBase*> Children = Node->K2_GetChildren();
				const UComboGraphNodeAnimBase* Child = Children[0];

				TestEqual("Child Title", Child->GetNodeTitle().ToString(), "Melee_B");
				TestEqual("Child Title", Child->K2_GetNodeTitle().ToString(), "Melee_B");
			});

			It("GetOwningGraph()", [this]()
			{
				TestEqual("Owning Graph", Node->K2_GetOwningGraph(), ComboGraph);
			});

			It("GetOwningTask()", [this]()
			{
				const UComboGraphAbilityTask_StartGraph* Task = Node->K2_GetOwningTask();
				TESTS_LOG(Display, TEXT("GetOwningTask() %s"), *GetNameSafe(Task))
				TestTrue("Owning Task", Task != nullptr);
				TestTrue("Owning Task Name Valid", GetNameSafe(Task).StartsWith("ComboGraphAbilityTask_StartGraph_"));
			});

			It("GetOwningAbility()", [this]()
			{
				const UGameplayAbility* Ability = Node->K2_GetOwningAbility();
				TESTS_LOG(Display, TEXT("GetOwningAbility() %s"), *GetNameSafe(Ability))
				TestTrue("Owning Ability", Ability != nullptr);
				TestEqual("Owning Ability Name", *GetNameSafe(Ability), "GA_Combo_TestFixture_C_0");
			});

			It("GetPreviousNode()", [this]()
			{
				TestTrue("Previous Node is not set if not continuing combo", Node->K2_GetPreviousNode() == nullptr);
				// TODO: Transition to next node and check it up
			});

			It("GetOwnerActor()", [this]()
			{
				TestTrue("Owner Actor is returning something", Node->GetOwnerActor() != nullptr);
				TestEqual("Avatar Actor is the one expected", GetNameSafe(Node->GetOwnerActor()), SourceActor->GetName());
			});

			It("GetAvatarActor()", [this]()
			{
				TestTrue("Avatar Actor is returning something", Node->GetAvatarActor() != nullptr);
				TestEqual("Avatar Actor is the one expected", GetNameSafe(Node->GetAvatarActor()), SourceActor->GetName());
			});

			It("GetAvatarAsPawn()", [this]()
			{
				TestTrue("Avatar Actor is returning something", Node->GetAvatarAsPawn() != nullptr);
				TestEqual("Avatar Actor is the one expected", GetNameSafe(Node->GetAvatarAsPawn()), SourceActor->GetName());
			});

			It("GetAvatarAsCharacter()", [this]()
			{
				TestTrue("Avatar Actor is returning something", Node->GetAvatarAsCharacter() != nullptr);
				TestEqual("Avatar Actor is the one expected", GetNameSafe(Node->GetAvatarAsCharacter()), SourceActor->GetName());
			});
		});

		AfterEach([this]()
		{
			TeardownWorld();
		});
	});
}
