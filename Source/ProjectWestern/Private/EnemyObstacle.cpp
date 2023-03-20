// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyObstacle.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CharacterRunner.h"
#include "MainGameModeBase.h"

// Sets default values
AEnemyObstacle::AEnemyObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshEnemy = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshEnemy"));
	MeshEnemy->SetupAttachment(RootComponent);

	SphereCollisionEnemy = CreateDefaultSubobject<USphereComponent>(FName("SphereCollision"));
	SphereCollisionEnemy->SetupAttachment(MeshEnemy);

	SphereCollisionEnemy->OnComponentBeginOverlap.AddDynamic(this, &AEnemyObstacle::BeginDestroyPlayer);
}

// Called when the game starts or when spawned
void AEnemyObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemyObstacle::BeginDestroyPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	CharacterRunner = Cast<ACharacterRunner>(OtherActor);
	if (IsValid(CharacterRunner))
	{
		CharacterRunner->Destroy(true);
		ViewportDeathHUD();
	}
}

void AEnemyObstacle::ViewportDeathHUD()
{
	GameMode = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode());
	GameMode->ChangeHUDState(GameMode->HUD_Death);
}

// Called every frame
void AEnemyObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

