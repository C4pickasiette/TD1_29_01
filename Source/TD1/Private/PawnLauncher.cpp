// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnLauncher.h"
#include "Projectile.h"
#include "GameModeBaseTD1.h"

void APawnLauncher::SpawnProjectile()
{
	if (RemainingProjectiles > 0)
	{
		FVector location = GetActorLocation();
		FRotator rotation = GetControlRotation();

		AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, location, rotation);

		RemainingProjectiles--;

		if (RemainingProjectiles == 0)
		{
			// Reload level
			AGameModeBaseTD1::reloadLevel(this);
		}
	}
}

void APawnLauncher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("SpawnProjectile", IE_Pressed, this, &APawnLauncher::SpawnProjectile);
}