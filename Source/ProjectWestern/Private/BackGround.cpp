// Fill out your copyright notice in the Description page of Project Settings.


#include "BackGround.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
ABackGround::ABackGround()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABackGround::BeginPlay()
{
	Super::BeginPlay();
}

void ABackGround::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

