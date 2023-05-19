//Engine
#include "Floor.h"

//Project
#include "MainGameModeBase.h"

// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(FName("Floor"));
}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
	
	GameMode = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode());
	GameMode->ChangeHUDState(EHUDState::HUD_InGame);
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

