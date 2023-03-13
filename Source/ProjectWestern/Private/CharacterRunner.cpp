// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterRunner.h"

// Sets default values
ACharacterRunner::ACharacterRunner()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterRunner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterRunner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

