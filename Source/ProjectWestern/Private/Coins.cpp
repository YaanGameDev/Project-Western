#include "Coins.h"

//Engine
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

//Project
#include "CharacterRunner.h"
#include "PlayerTest.h"

// Sets default values
ACoins::ACoins()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionCoins = CreateDefaultSubobject<USphereComponent>(FName("CollisionCoins"));
	RootComponent = CollisionCoins;

	CollisionCoins->OnComponentBeginOverlap.AddDynamic(this, &ACoins::BeginCollisionCoins);
}

// Called when the game starts or when spawned
void ACoins::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoins::BeginCollisionCoins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerTest = Cast<APlayerTest>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (IsValid(PlayerTest))
	{
	
	}
}

// Called every frame
void ACoins::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
