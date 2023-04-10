#include "SettingsCoin.h"

//Engine
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Components/SphereComponent.h"


//Project
#include "Coins.h"


// Sets default values
ASettingsCoin::ASettingsCoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnCoinsLocation = CreateDefaultSubobject<USphereComponent>(FName("SpawnCoinsLocation"));
	SpawnCoinsLocation->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASettingsCoin::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerStartCoins;
	GetWorldTimerManager().SetTimer(TimerStartCoins, this, &ASettingsCoin::FunctionSpawnCoins, FMath::RandRange(minTimeSpawn, maxTimeSpawn), false);
}

void ASettingsCoin::FunctionSpawnCoins()
{
	TArray<AActor*>LocalCoins;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpawnCoins, LocalCoins);

	if (LocalCoins.Num() < 10)
	{
		FActorSpawnParameters CoinsParameters = FActorSpawnParameters();

		GetWorld()->SpawnActor<ACoins>(SpawnCoins, GetActorLocation(), GetActorRotation(), CoinsParameters);

		FTimerHandle TimerSpawnCoins;
		GetWorldTimerManager().SetTimer(TimerSpawnCoins, this, &ASettingsCoin::FunctionSpawnCoins, FMath::RandRange(minTimeSpawn, maxTimeSpawn), false);
	}
}

// Called every frame
void ASettingsCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

