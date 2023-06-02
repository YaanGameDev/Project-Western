// Fill out your copyright notice in the Description page of Project Settings.


#include "BackgroundElement.h"

#include "MainGameModeBase.h"

// Sets default values
ABackgroundElement::ABackgroundElement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABackgroundElement::BeginPlay()
{
	Super::BeginPlay();
	GameMode = AMainGameModeBase::GetGameMode(this);

	SpawnLocation = GetActorLocation() + FVector{0, TargetDistance, 0};
	StartLocation = GetActorLocation();
}

// Called every frame
void ABackgroundElement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector CurrentLocation = GetActorLocation() + VelocityBackGround * DeltaTime;
	SetActorLocation(CurrentLocation);

	if (CurrentLocation.Y < StartLocation.Y - TargetDistance)
	{
		SetActorLocation(StartLocation);
	}

}

