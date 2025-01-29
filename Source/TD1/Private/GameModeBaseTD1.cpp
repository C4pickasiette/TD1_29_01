// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBaseTD1.h"
#include "Kismet/GameplayStatics.h"

int AGameModeBaseTD1::TotalCollisionCount = 0;

void AGameModeBaseTD1::reloadLevel(UObject* WorldContextObject)
{
	FString LevelName = UGameplayStatics::GetCurrentLevelName(WorldContextObject, true);
	UGameplayStatics::OpenLevel(WorldContextObject, FName(*LevelName));
}

void AGameModeBaseTD1::increaseScore()
{
	TotalCollisionCount++;

	FString Message = FString::Printf(TEXT("Score : %d"), TotalCollisionCount);
	GEngine->AddOnScreenDebugMessage(2, 100.0f, FColor::Black, Message);
}




