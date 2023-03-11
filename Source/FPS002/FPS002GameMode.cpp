// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPS002GameMode.h"
#include "FPS002Character.h"
#include "UObject/ConstructorHelpers.h"

AFPS002GameMode::AFPS002GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	restartCounter = 0;

}

void AFPS002GameMode::SetRestartCounter(int newRestartCounter)
{
	restartCounter = newRestartCounter;
}

int AFPS002GameMode::GetRestartCounter()
{
	return restartCounter;
}
