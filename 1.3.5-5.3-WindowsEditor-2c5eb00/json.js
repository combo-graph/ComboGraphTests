const json = {
    "devices": [
        {
            "deviceName": "DESKTOP-TAT57NG",
            "instance": "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3",
            "platform": "WindowsEditor",
            "oSVersion": "Windows 11 (22H2) [10.0.22621.2070] ",
            "model": "Default",
            "gPU": "NVIDIA GeForce RTX 3080",
            "cPUModel": "AMD Ryzen 9 7950X 16-Core Processor            ",
            "rAMInGB": 64,
            "renderMode": "SM5",
            "rHI": "",
            "appInstanceLog": ""
        }
    ],
    "reportCreatedOn": "2023.08.02-17.06.07",
    "succeeded": 8,
    "succeededWithWarnings": 0,
    "failed": 16,
    "notRun": 0,
    "inProcess": 0,
    "totalDuration": 493.2242431640625,
    "comparisonExported": false,
    "comparisonExportDirectory": "",
    "tests": [
        {
            "testDisplayName": "should decrease stamina on ability activation when playing first montage",
            "fullTestPath": "ComboGraph.Feature Testing.should decrease stamina on ability activation when playing first montage",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.189868927001953,
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
                    "timestamp": "2023.08.02-14.57.51"
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
                    "timestamp": "2023.08.02-14.57.51"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogAnimationCompression: Building compressed animation data for AnimSequence /ComboGraphTests/Fixtures/Animations/Melee_A.Melee_A",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-14.57.51"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogAnimationCompression: Storing compressed animation data for /ComboGraphTests/Fixtures/Animations/Melee_A.Melee_A, at AnimationSequence/23b39846c51583e608e59f38f3d06023cb09cec0",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-14.57.51"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-14.58.21"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetCurrentNode()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphAbilityTask_StartGraph.GetCurrentNode()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.020214080810547,
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
                    "timestamp": "2023.08.02-14.58.22"
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
                    "timestamp": "2023.08.02-14.58.22"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-14.58.52"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetPreviousNode()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphAbilityTask_StartGraph.GetPreviousNode()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.02031898498535,
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
                    "timestamp": "2023.08.02-14.58.52"
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
                    "timestamp": "2023.08.02-14.58.52"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-14.59.22"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "first node should be anim based",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.first node should be anim based",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.020254135131836,
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
                    "timestamp": "2023.08.02-14.59.22"
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
                    "timestamp": "2023.08.02-14.59.22"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-14.59.52"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetAnimationAsset()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetAnimationAsset()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.0202693939209,
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
                    "timestamp": "2023.08.02-14.59.52"
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
                    "timestamp": "2023.08.02-14.59.52"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.00.22"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetAnimationClass()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetAnimationClass()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.020511627197266,
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
                    "timestamp": "2023.08.02-15.00.22"
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
                    "timestamp": "2023.08.02-15.00.22"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.00.52"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetAvatarActor()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetAvatarActor()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.02072525024414,
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
                    "timestamp": "2023.08.02-15.00.52"
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
                    "timestamp": "2023.08.02-15.00.52"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.01.22"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetAvatarAsCharacter()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetAvatarAsCharacter()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.020368576049805,
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
                    "timestamp": "2023.08.02-15.01.23"
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
                    "timestamp": "2023.08.02-15.01.23"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.01.53"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetAvatarAsPawn()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetAvatarAsPawn()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.020122528076172,
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
                    "timestamp": "2023.08.02-15.01.53"
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
                    "timestamp": "2023.08.02-15.01.53"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.02.23"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetChildren()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetChildren()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.02045440673828,
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
                    "timestamp": "2023.08.02-15.02.23"
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
                    "timestamp": "2023.08.02-15.02.23"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.02.53"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetNodeTitle()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetNodeTitle()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.02036476135254,
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
                    "timestamp": "2023.08.02-15.02.53"
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
                    "timestamp": "2023.08.02-15.02.53"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.03.23"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetOwnerActor()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetOwnerActor()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.021203994750977,
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
                    "timestamp": "2023.08.02-15.03.23"
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
                    "timestamp": "2023.08.02-15.03.23"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.03.53"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetOwningAbility()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetOwningAbility()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.020124435424805,
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
                    "timestamp": "2023.08.02-15.03.53"
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
                    "timestamp": "2023.08.02-15.03.53"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.04.23"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetOwningGraph()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetOwningGraph()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.020475387573242,
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
                    "timestamp": "2023.08.02-15.04.23"
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
                    "timestamp": "2023.08.02-15.04.23"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.04.53"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetOwningTask()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetOwningTask()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.020292282104492,
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
                    "timestamp": "2023.08.02-15.04.54"
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
                    "timestamp": "2023.08.02-15.04.54"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.05.24"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "GetPreviousNode()",
            "fullTestPath": "ComboGraph.Nodes.ComboGraph Task and Nodes API.Task / Node.UComboGraphNodeAnimBase.GetPreviousNode()",
            "state": "Fail",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 30.02017593383789,
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
                    "timestamp": "2023.08.02-15.05.24"
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
                    "timestamp": "2023.08.02-15.05.24"
                },
                {
                    "event": {
                        "type": "Error",
                        "message": "Latent command timed out.",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "F:\\Engines\\UE_5.3\\Engine\\Source\\Runtime\\Core\\Public\\Misc\\AutomationTest.h",
                    "lineNumber": 2309,
                    "timestamp": "2023.08.02-15.05.54"
                }
            ],
            "warnings": 0,
            "errors": 1,
            "artifacts": []
        },
        {
            "testDisplayName": "should have attributes initialized",
            "fullTestPath": "ComboGraph.Basics.should have attributes initialized",
            "state": "Success",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 0.030719801783561707,
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
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 0.010928601026535034,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "should have attributes initialized",
            "fullTestPath": "ComboGraph.Feature Testing.should have attributes initialized",
            "state": "Success",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 0.01114480197429657,
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
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 0.011349499225616455,
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
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 0.011673897504806519,
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
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 0.012092102319002151,
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
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 0.011576801538467407,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        },
        {
            "testDisplayName": "F_ComboGraph_Test",
            "fullTestPath": "Project.Functional Tests.ComboGraphTests.FunctionalTests.Maps.F_ComboGraph_Map.F_ComboGraph_Test",
            "state": "Success",
            "deviceInstance": [
                "DESKTOP-TAT57NG-D8675C1B4F50C2177CAD1DB18EA6BB0B-76B3AA2E4C281373CF521FBF6D1972D3"
            ],
            "duration": 12.629018783569336,
            "dateTime": "0001.01.01-00.00.00",
            "entries": [
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test: Float assertion passed (Should have stamina decreased by 10  (0))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.05.57"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogAnimationCompression: Building compressed animation data for AnimSequence /ComboGraphTests/Fixtures/Animations/Melee_B.Melee_B",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.05.58"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test: Float assertion passed (Should have stamina decreased by 10  (1))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.05.58"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogAnimationCompression: Storing compressed animation data for /ComboGraphTests/Fixtures/Animations/Melee_B.Melee_B, at AnimationSequence/490fbf8c73838b26af5cc6d97de9b8720e17d8d2",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.05.58"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogAnimationCompression: Building compressed animation data for AnimSequence /ComboGraphTests/Fixtures/Animations/Melee_C.Melee_C",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.06.00"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test: Float assertion passed (Should have stamina decreased by 10  (2))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.06.00"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "LogAnimationCompression: Storing compressed animation data for /ComboGraphTests/Fixtures/Animations/Melee_C.Melee_C, at AnimationSequence/94f0ae0abf45f05373f9702c7219dae6f46205d0",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.06.00"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test: Float assertion passed (Should have stamina decreased by 10  (3))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.06.02"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test: Float assertion passed (Should have stamina decreased by 10  (4))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.06.03"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test: Float assertion passed (Should have stamina decreased by 10  (5))",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.06.05"
                },
                {
                    "event": {
                        "type": "Info",
                        "message": "F_ComboGraph_Test: Float assertion passed (Should have stamina decreased to 25 after 3 attacks)",
                        "context": "",
                        "artifact": "00000000000000000000000000000000"
                    },
                    "filename": "",
                    "lineNumber": -1,
                    "timestamp": "2023.08.02-15.06.06"
                }
            ],
            "warnings": 0,
            "errors": 0,
            "artifacts": []
        }
    ]
};
