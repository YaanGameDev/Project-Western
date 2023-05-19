// Fill out your copyright notice in the Description page of Project Settings.


#include "WallDestroyActors.h"

//Engine
#include "Components/BoxComponent.h"

//Project
#include "EnemyObstacle.h"
#include "Coins.h"
#include "NPC_Enemy.h"


// Sets default values
AWallDestroyActors::AWallDestroyActors()
{
 
	WallDestroyActors = CreateDefaultSubobject<UBoxComponent>(FName("WallDestroyActors"));

	WallDestroyActors->OnComponentBeginOverlap.AddDynamic(this, &AWallDestroyActors::BeginCollisionWall);

}

// Called when the game starts or when spawned
void AWallDestroyActors::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWallDestroyActors::BeginCollisionWall(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Obstacle = Cast<AEnemyObstacle>(OtherActor);
	Coins = Cast<ACoins>(OtherActor);
	NPC_Enemy = Cast<ANPC_Enemy>(OtherActor);
	if (IsValid(Obstacle))
	{
		Obstacle->Destroy();
	}
	else if (IsValid(NPC_Enemy))
	{
		NPC_Enemy->Destroy();
	}
	else if (IsValid(Coins))
	{
		Coins->Destroy();
	}
}

