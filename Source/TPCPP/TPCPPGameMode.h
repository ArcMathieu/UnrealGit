// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPCPPGameMode.generated.h"

UCLASS(minimalapi)
class ATPCPPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATPCPPGameMode();
	void Respawn(AController* controller);
};



