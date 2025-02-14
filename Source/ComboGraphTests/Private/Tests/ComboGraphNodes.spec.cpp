// Copyright 2021 Mickael Daniel. All Rights Reserved.

#include "ComboGraphTestsLog.h"
#include "Abilities/ComboGraphTestAbilitySystemCharacter.h"
#include "Abilities/ComboGraphTestStaminaSet.h"
#include "Abilities/Tasks/ComboGraphAbilityTask_StartGraph.h"
#include "Graph/ComboGraph.h"
#include "Graph/ComboGraphNodeAnimBase.h"
#include "Graph/ComboGraphNodeEntry.h"
#include "Misc/AutomationTest.h"
#include "Misc/EngineVersionComparison.h"

#if UE_VERSION_OLDER_THAN(5, 5, 0)
#include "ComboGraphTestFlags.h"
#endif

BEGIN_DEFINE_SPEC(FComboGraphNodesSpec, "ComboGraph.Nodes", EAutomationTestFlags::ProductFilter | EAutomationTestFlags_ApplicationContextMask)
	UWorld* World;

	UComboGraph* ComboGraph;
	UComboGraphNodeAnimBase* Node;
	TSubclassOf<UGameplayAbility> AbilityType;

	AComboGraphTestAbilitySystemCharacter* SourceActor;
	UAbilitySystemComponent* SourceASC;
	APlayerController* SourceController;

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

END_DEFINE_SPEC(FComboGraphNodesSpec)

void FComboGraphNodesSpec::Define()
{
	Describe("ComboGraph Task and Nodes API", [this]()
	{
		BeforeEach([this]()
		{
			// Setup tests
			CreateAndSetupWorld();

			UClass* ActorType = StaticLoadClass(AComboGraphTestAbilitySystemCharacter::StaticClass(), nullptr, TEXT("/ComboGraphTests/Fixtures/Characters/BP_Test_AbilitySystemCharacter.BP_Test_AbilitySystemCharacter_C"));
			AbilityType = StaticLoadClass(UGameplayAbility::StaticClass(), nullptr, TEXT("/ComboGraphTests/Fixtures/GA_Combo_TestFixture.GA_Combo_TestFixture_C"));

			// set up the source actor
			SourceActor = CastChecked<AComboGraphTestAbilitySystemCharacter>(World->SpawnActor(ActorType, nullptr, nullptr, FActorSpawnParameters()));
			SourceASC = SourceActor->GetAbilitySystemComponent();

			// Possess and make source actor behave like a player controller actor
			SourceController = World->SpawnActor<APlayerController>();
			SourceController->Possess(SourceActor);

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

		// Latent action seems to be broken on 5.3 preview
		Describe("Task / Node", [this]()
		{
			LatentBeforeEach([this](const FDoneDelegate& Done)
			{
				check(ComboGraph);
				Node = Cast<UComboGraphNodeAnimBase>(ComboGraph->FirstNode);

				if (!SourceActor->HasActorBegunPlay())
				{
					// Make sure ability is granted
					TESTS_LOG(Display, TEXT("DispatchBeginPlay()"))
					SourceActor->DispatchBeginPlay();

					// And activated once, to make sure Node is updated with gameplay task owner interface calls
					TESTS_LOG(Display, TEXT("TryActivateAbilityByClass(%s)"), *GetNameSafe(AbilityType))
					SourceASC->TryActivateAbilityByClass(AbilityType);

					// Async task offload on game thread seems to be necessary on 5.3 / 5.4 - likely engine bug. Test without on future engine updates.
					AsyncTask(ENamedThreads::GameThread, [this, Done]()
					{
						FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateLambda([this, Done](float Delta)
						{
							Done.Execute();
							return false;
						}), 1.2f);
					});

					TickWorld(1.f);
				}
			});

			Describe("UComboGraphAbilityTask_StartGraph", [this]()
			{
				It("GetCurrentNode()", [this]()
				{
					const UComboGraphAbilityTask_StartGraph* Task = Node->K2_GetOwningTask();
					TestTrue("Owning Task", Task != nullptr);
					TestTrue("Owning Task Name Valid", GetNameSafe(Task).StartsWith("ComboGraphAbilityTask_StartGraph_"));
					TestEqual("Current Node is set to first descendant node of entry", Task->GetCurrentNode(), Node);
				});

				It("GetPreviousNode()", [this]()
				{
					AddInfo(FString::Printf(TEXT("Test against %s"), *GetNameSafe(ComboGraph->EntryNode)));
					const UComboGraphAbilityTask_StartGraph* Task = Node->K2_GetOwningTask();
					TestTrue("Owning Task", Task != nullptr);
					TestTrue("Owning Task Name Valid", GetNameSafe(Task).StartsWith("ComboGraphAbilityTask_StartGraph_"));
					TestTrue("Previous Node is set to entry node on first activation", Task->GetPreviousNode() == ComboGraph->EntryNode);
				});
			});

			Describe("UComboGraphNodeAnimBase", [this]()
			{
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
					TestTrue("Previous Node is set to entry node on first activation", Node->K2_GetPreviousNode() == ComboGraph->EntryNode);
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
		});

		AfterEach([this]()
		{
			// Destroy the actors
			if (SourceActor)
			{
				World->EditorDestroyActor(SourceActor, false);
			}

			if (SourceController)
			{
				World->EditorDestroyActor(SourceController, false);
			}

			if (TargetActor)
			{
				World->EditorDestroyActor(TargetActor, false);
			}

			TeardownWorld();
		});
	});
}
