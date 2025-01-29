// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeBaseTD1.generated.h"

/**
 * 
 */
UCLASS()
class TD1_API AGameModeBaseTD1 : public AGameModeBase
{
	GENERATED_BODY()

public:
	static void reloadLevel(UObject* WorldContextObject);

	static void increaseScore();
	
	static int TotalCollisionCount;

};
