// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}
// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	Impulse();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::Impulse()
{
	FVector impulseVector = GetActorForwardVector() * 60000;
	if (MeshComponent)
	{
		MeshComponent->AddImpulse(impulseVector);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Impulse mesh component is not real"))
	}
}

