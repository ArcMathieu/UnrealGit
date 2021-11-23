// Copyright Epic Games, Inc. All Rights Reserved.

#include "TPCPPGameMode.h"
#include "TPCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"

ATPCPPGameMode::ATPCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
}

void ATPCPPGameMode::Respawn(AController* controller)
{
	if (controller)
	{
		FVector RespawnLocation = FVector(-350, 700, 200);
		if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, RespawnLocation, FRotator::ZeroRotator))
		{
			controller->Possess(Pawn);
		}
	}
}
