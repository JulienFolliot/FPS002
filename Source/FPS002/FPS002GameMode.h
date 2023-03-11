// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPS002GameMode.generated.h"

UCLASS(minimalapi)
class AFPS002GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFPS002GameMode();

	/** int to count restart */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Custom)
	int restartCounter;

	/** Setter to set the int */
	UFUNCTION(BlueprintCallable, Category = Custom)
	void SetRestartCounter(int newRestartCounter);

	/** Getter for the int */
	UFUNCTION(BlueprintCallable, Category = Custom)
	int GetRestartCounter();
};



