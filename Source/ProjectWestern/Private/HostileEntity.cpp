// Fill out your copyright notice in the Description page of Project Settings.


#include "HostileEntity.h"

#include "MainGameModeBase.h"

// Sets default values
AHostileEntity::AHostileEntity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHostileEntity::BeginPlay()
{
	Super::BeginPlay();
	GameMode = AMainGameModeBase::GetGameMode(this);
}

void AHostileEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (Velocity * GameMode->CurrentDifficultyFactor) * DeltaTime;
	SetActorLocation(CurrentLocation);

}

