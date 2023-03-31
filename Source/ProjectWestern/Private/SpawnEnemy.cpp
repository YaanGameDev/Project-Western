#include "SpawnEnemy.h"

//Engine
#include "Math/UnrealMathUtility.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Actor.h"


//Project
#include "NPC_Enemy.h"
#include "EnemyObstacle.h"

// Sets default values
ASpawnEnemy::ASpawnEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnEnemyLocation = CreateDefaultSubobject<UBoxComponent>(FName("SpawnEnemyLocation"));
	SpawnEnemyLocation->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ASpawnEnemy::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle SpawnRandom;
	GetWorldTimerManager().SetTimer(SpawnRandom, this, &ASpawnEnemy::SpawnEntity, 10, false);
}

void ASpawnEnemy::ObstacleEnemyLocation()
{
	TArray<AActor*> LocalObstacle;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpawnObstacle, LocalObstacle);

	if (LocalObstacle.IsEmpty())
	{
		FActorSpawnParameters ObstacleSpawnParameters = FActorSpawnParameters();

		GetWorld()->SpawnActor<AEnemyObstacle>(SpawnObstacle, GetActorLocation(), GetActorRotation(), ObstacleSpawnParameters);

		FTimerHandle NewSpawnRandom;
		GetWorldTimerManager().SetTimer(NewSpawnRandom, this, &ASpawnEnemy::SpawnEntity, FMath::RandRange(Spawn1,Spawn2), false);
	}
}

void ASpawnEnemy::SpawnEntity()
{
}

// Called every frame
void ASpawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ObstacleEnemyLocation();
}

