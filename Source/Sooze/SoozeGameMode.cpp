// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoozeGameMode.h"
#include "SoozeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASoozeGameMode::ASoozeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
