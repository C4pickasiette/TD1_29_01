// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "PawnLauncher.generated.h"

/**
 * 
 */
UCLASS()
class TD1_API APawnLauncher : public ADefaultPawn
{
	GENERATED_BODY()
	
public:
	void SpawnProjectile();


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, Category = "Projectile")
	TSubclassOf<AActor> ProjectileBlueprint;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	int RemainingProjectiles;

};
