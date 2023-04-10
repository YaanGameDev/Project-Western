#include "PlayerTest.h"


//Engine
#include "Kismet/GameplayStatics.h"

//Project
#include "MainGameModeBase.h"

// Sets default values
APlayerTest::APlayerTest()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerTest::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoverWS", this, &APlayerTest::MoverPlayerWS);
	InputComponent->BindAxis("MoverAD", this, &APlayerTest::MoverPlayerAD);
}

void APlayerTest::MoverPlayerWS(float Valor)
{
	AddMovementInput(GetActorForwardVector() * Valor);
}

void APlayerTest::MoverPlayerAD(float Valor)
{
	AddMovementInput(GetActorRightVector() * Valor);
}

