// Copyright 2021 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

COMBOGRAPHTESTS_API DECLARE_LOG_CATEGORY_EXTERN(LogComboGraphTests, Display, All);

#define TESTS_LOG(Verbosity, Format, ...) \
{ \
    UE_LOG(LogComboGraphTests, Verbosity, Format, ##__VA_ARGS__); \
}
