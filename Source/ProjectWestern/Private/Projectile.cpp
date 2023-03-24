// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

//Engine
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

//Project
#include "Weapon.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Projectile = CreateDefaultSubobject<UStaticMeshComponent>(FName("Projectile"));
	RootComponent = Projectile;

	CollisionProjectile = CreateDefaultSubobject<USphereComponent>(FName("CollisionProjectile"));
	CollisionProjectile->SetupAttachment(Projectile);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FRotator CurrentRotation = GetActorRotation();
	CurrentLocation.Y -= VelocityProjectile;
	SetActorLocation(CurrentLocation);
}