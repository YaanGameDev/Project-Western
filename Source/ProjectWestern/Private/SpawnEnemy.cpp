#include "SpawnEnemy.h"

//Engine
#include "Math/UnrealMathUtility.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/TargetPoint.h"
#include "Components/SphereComponent.h"

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

	

}

void ASpawnEnemy::EnemyLocation()
{
	TArray<AActor*> LocalEnemy;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANPC_Enemy::StaticClass(), LocalEnemy);

	if (LocalEnemy.IsEmpty())
	{
		FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
		
		GetWorld()->SpawnActor<ANPC_Enemy>(SpawnEnemy, GetActorLocation(), GetActorRotation(), SpawnParameters);
	}
}

// Called every frame
void ASpawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	EnemyLocation();

}

