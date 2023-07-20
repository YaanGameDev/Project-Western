// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

//Engine
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

//Project
#include "Weapon.h"
#include "CharacterRunner.h"
#include "NPC_Enemy.h"
#include "MainGameModeBase.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Projectile = CreateDefaultSubobject<UStaticMeshComponent>(FName("Projectile"));
	Projectile->SetRelativeScale3D(FVector(10.f, 10.f, 10.f));
	Projectile->SetRelativeRotation(FRotator3d(0.0f, 0.f, 0.f));
	RootComponent = Projectile;

	CollisionProjectile = CreateDefaultSubobject<USphereComponent>(FName("CollisionProjectile"));
	CollisionProjectile->SetRelativeScale3D(FVector(0.7f, 0.7f, 0.7f));
	CollisionProjectile->SetupAttachment(Projectile);

	CollisionProjectile->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::BeginCollisionProjectile);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();


}

void AProjectile::BeginCollisionProjectile(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Enemy = Cast<ANPC_Enemy>(OtherActor);
	if (IsValid(Enemy))
	{
		TArray<AActor*>Actors;
		GetOverlappingActors(Actors);
		for (AActor* Actor : Actors)
		{
			if (Enemy)
			{
				AddEnemies();
				Enemy->EnemyDeathFunction();
				Enemy->SetActorEnableCollision(false);
				this->Destroy();
			}
		}
	}
}

void AProjectile::AddEnemies()
{
	AMainGameModeBase* GameMode = Cast<AMainGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GameMode->AddEnemies();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentDirection = GetActorLocation();
	CurrentDirection = CurrentDirection + VelocityProjectile * DeltaTime;
	SetActorLocation(CurrentDirection);
}