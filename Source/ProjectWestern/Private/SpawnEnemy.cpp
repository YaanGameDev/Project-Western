#include "SpawnEnemy.h"

//Engine
#include "Math/UnrealMathUtility.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
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

	FTimerHandle RandomSpawn;
	GetWorldTimerManager().SetTimer(RandomSpawn, this, &ASpawnEnemy::ObstacleEnemyLocation, FMath::RandRange(minSpawnTime, maxSpawnTime), false);
}

void ASpawnEnemy::ObstacleEnemyLocation()
{
	TArray<AActor*> LocalObstacle;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpawnEnemy, LocalObstacle);

	if (LocalObstacle.Num() < 6)
	{
		FActorSpawnParameters ObstacleSpawnParameters = FActorSpawnParameters();

		GetWorld()->SpawnActor<AActor>(SpawnEnemy, GetActorLocation(), GetActorRotation(), ObstacleSpawnParameters);

		FTimerHandle TimerRandomSpawn;
		GetWorldTimerManager().SetTimer(TimerRandomSpawn, this, &ASpawnEnemy::ObstacleEnemyLocation, FMath::RandRange(minSpawnTime, maxSpawnTime), false);
	}
}

// Called every frame
void ASpawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

