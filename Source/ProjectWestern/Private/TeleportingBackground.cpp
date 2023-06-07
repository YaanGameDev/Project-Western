// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportingBackground.h"

//Engine
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"

//Project
#include "BackgroundElement.h"

// Sets default values
ATeleportingBackground::ATeleportingBackground()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WallTeleportBackground = CreateDefaultSubobject<UBoxComponent>(FName("WallTeleporting"));
	RespawnLocation = CreateDefaultSubobject<USphereComponent>(FName("RespawnLocation"));

	WallTeleportBackground->OnComponentBeginOverlap.AddDynamic(this, &ATeleportingBackground::BeginWallTeleporting);
}

// Called when the game starts or when spawned
void ATeleportingBackground::BeginPlay()
{
	Super::BeginPlay();

	RespawnTarget = RespawnLocation->GetComponentLocation();
}

void ATeleportingBackground::BeginWallTeleporting(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	BackGround = Cast<ABackgroundElement>(OtherActor);
	if (IsValid(BackGround))
	{
		BackGround->SetActorLocation(RespawnTarget);
	}
}

// Called every frame
void ATeleportingBackground::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

