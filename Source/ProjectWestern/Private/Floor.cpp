//Engine
#include "Floor.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"

//Project
#include "MainGameModeBase.h"
#include "CharacterRunner.h"

// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));
	Floor->SetupAttachment(SceneComponent);

	AttachPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("AttachPoint"));
	AttachPoint->SetupAttachment(SceneComponent);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	TriggerBox->InitBoxExtent(FVector(20.f, 5.f, 5.f));
	TriggerBox->SetupAttachment(SceneComponent);

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AFloor::BeginTriggerBox);
}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
	
	GameMode = Cast<AMainGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GameMode->ChangeHUDState(EHUDState::HUD_InGame);

	check(GameMode);
}

void AFloor::BeginTriggerBox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CharacterRunner = Cast<ACharacterRunner>(OtherActor);
	if (IsValid(CharacterRunner))
	{
		GameMode->AddFloor();

		GetWorldTimerManager().SetTimer(TimerDestroyFloor, this, &AFloor::DestroyFloor, 8.f, false);
	}
}

void AFloor::DestroyFloor()
{
	if (TimerDestroyFloor.IsValid())
	{
		GetWorldTimerManager().ClearTimer(TimerDestroyFloor);
	}
	this->Destroy();
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

