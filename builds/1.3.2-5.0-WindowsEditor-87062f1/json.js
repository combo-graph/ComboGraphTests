const json = {
    "devices": [
        {
            "deviceName": "DESKTOP-TAT57NG",
            "instance": "DESKTOP-TAT57NG-CDD656F140803D83516E3E9CB9E29EE6",
            "platform": "WindowsEditor",
            "oSVersion": "Windows 11 (22H2) [10.0.22621.1105] ",
            "model": "Default",
            "gPU": "NVIDIA GeForce RTX 3080",
            "cPUModel": "AMD Ryzen 9 7950X 16-Core Processor            ",
            "rAMInGB": 64,
            "renderMode": "SM5",
            "rHI": "",
            "appInstanceLog": ""
        }
    ],
    "reportCreatedOn": "2023.01.13-01.02.39",
    "succeeded": 24,
    "succeededWithWarnings": 0,
    "failed": 0,
    "notRun": 0,
    "inProcess": 0,
    "totalDuration": 12.956192016601562,
    "comparisonExported": false,
    "comparisonExportDirectory": "",
    "tests": [
        {
            "testDisplayName": "should have attributes initialized",
            "fullTestPath": "ComboGraph.Basics.should have attributes initialized",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.024332799017429352,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "should setup world and such",
            "fullTestPath": "ComboGraph.Basics.should setup world and such",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.010312501341104507,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "should decrease stamina on ability activation when playing first montage",
            "fullTestPath": "ComboGraph.Feature Testing.should decrease stamina on ability activation when playing first montage",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.11562799662351608,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogStaticMesh: Building static mesh SM_Cube_Weapon...",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.22"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogSkeletalMesh: Waiting for skinned assets to be ready 0/1 (SK_Mannequin) ...",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.23"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "should have attributes initialized",
            "fullTestPath": "ComboGraph.Feature Testing.should have attributes initialized",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.010926902294158936,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "should setup world and such",
            "fullTestPath": "ComboGraph.Feature Testing.should setup world and such",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.010740399360656738,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "ComboGraph should be created",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.ComboGraph should be created",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.010905299335718155,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "EntryNode is created",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.ComboGraph.EntryNode is created",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011203199625015259,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "FirstNode is created",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.ComboGraph.FirstNode is created",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.01093989983201027,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetCurrentNode()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphAbilityTask_StartGraph.GetCurrentNode()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.010966699570417404,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.23"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.23"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetPreviousNode()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphAbilityTask_StartGraph.GetPreviousNode()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011126101016998291,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.23"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.23"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "Test against ComboGraphNodeEntry_0",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.23"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "first node should be anim based",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.first node should be anim based",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011331900954246521,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.24"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.24"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetAnimationAsset()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetAnimationAsset()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.01151449978351593,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.24"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.24"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetAnimationClass()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetAnimationClass()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011499699205160141,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.24"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.24"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetAvatarActor()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetAvatarActor()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011528398841619492,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.24"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.24"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetAvatarAsCharacter()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetAvatarAsCharacter()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011233199387788773,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.25"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.25"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetAvatarAsPawn()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetAvatarAsPawn()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011299699544906616,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.25"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.25"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetChildren()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetChildren()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.012140199542045593,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.25"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.25"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetNodeTitle()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetNodeTitle()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011193599551916122,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.25"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.25"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetOwnerActor()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetOwnerActor()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011041499674320221,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.25"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.25"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetOwningAbility()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetOwningAbility()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011149797588586807,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.26"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.26"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: GetOwningAbility() GA_Combo_TestFixture_C_0",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.26"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetOwningGraph()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetOwningGraph()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011963900178670883,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.26"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.26"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetOwningTask()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetOwningTask()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.01168769970536232,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.26"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.26"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: GetOwningTask() ComboGraphAbilityTask_StartGraph_14",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.26"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "GetPreviousNode()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetPreviousNode()",
            "state": "Success",
            "deviceInstance": [],
            "duration": 0.011447500437498093,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: DispatchBeginPlay()",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.26"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogComboGraphTests: TryActivateAbilityByClass(GA_Combo_TestFixture_C)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.26"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "F_ComboGraph_Test",
            "fullTestPath": "Project.Functional Tests.GraphTests.FunctionalTests.Maps.F_ComboGraph_Map.F_ComboGraph_Test",
            "state": "Success",
            "deviceInstance": [],
            "duration": 12.580079078674316,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test_2: Float assertion passed (Should have stamina decreased by 10  (0))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.30"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test_2: Float assertion passed (Should have stamina decreased by 10  (1))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.31"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test_2: Float assertion passed (Should have stamina decreased by 10  (2))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.32"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test_2: Float assertion passed (Should have stamina decreased by 10  (3))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.35"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test_2: Float assertion passed (Should have stamina decreased by 10  (4))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.36"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test_2: Float assertion passed (Should have stamina decreased by 10  (5))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.38"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test_2: Float assertion passed (Should have stamina decreased to 25 after 3 attacks)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.01.13-00.02.39"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        }
    ]
};