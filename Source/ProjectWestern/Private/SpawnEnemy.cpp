#include "SpawnEnemy.h"

//Engine
#include "Math/UnrealMathUtility.h"
#include "Components/BoxComponent.h"

//Project
#include "NPC_Enemy.h"

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

	SpawnActor();

}

void ASpawnEnemy::SpawnActor()
{
	FActorSpawnParameters SpawnEnemyParameters;
	SpawnEnemyParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector SpawnLocation = SpawnEnemyLocation->GetComponentLocation();
	FRotator SpawnRotation = GetActorRotation();

	GetWorld()->SpawnActor<ANPC_Enemy>(SpawnEnemy, SpawnLocation, SpawnRotation, SpawnEnemyParameters);
}

// Called every frame
void ASpawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

