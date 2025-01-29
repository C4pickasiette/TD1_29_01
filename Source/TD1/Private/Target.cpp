// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"
#include "GameModeBaseTD1.h"
#include "Engine/Engine.h"


// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetNotifyRigidBodyCollision(true);

	MeshComponent->OnComponentHit.AddDynamic(this, &ATarget::OnHit);
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATarget::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
						FVector NormalImpulse, const FHitResult& Hit)
{
	if (NormalImpulse.Length() > 2000)
	{
		// Increas Score
		AGameModeBaseTD1::increaseScore();
	}
}

