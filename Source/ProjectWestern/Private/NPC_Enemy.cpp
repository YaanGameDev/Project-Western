
// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Enemy.h"

//Engine
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"

//Project
#include "CharacterRunner.h"
#include "MainGameModeBase.h"
#include "Projectile.h"

// Sets default values
ANPC_Enemy::ANPC_Enemy()
{
	PrimaryActorTick.bCanEverTick = true;

	NPC_Enemy = CreateDefaultSubobject<USkeletalMeshComponent>(FName("StaticMesh"));
	NPC_Enemy->SetRelativeRotation(FRotator3d(0.f, -90.f, 0.f));
	RootComponent = NPC_Enemy;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollision"));
	BoxCollision->SetupAttachment(NPC_Enemy);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ANPC_Enemy::BeginCollisionNPCEnemy);

}

void ANPC_Enemy::SetHealth(float Dano)
{
	if (Health >= 0.0f)
	{
		Health -= Dano;
	}
	else if (Health <= 0.0f)
	{
		Destroy();
	}
}

float ANPC_Enemy::GetHealth()
{
	return Health;
}

// Called when the game starts or when spawned
void ANPC_Enemy::BeginPlay()
{
	Super::BeginPlay();
}

void ANPC_Enemy::BeginCollisionNPCEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CharacterRunner = Cast<ACharacterRunner>(OtherActor);
	if (IsValid(CharacterRunner) && CharacterRunner->GetPlayerState() != EStateAnimationsPlayer::Death)
	{
		CharacterRunner->DeathFunction();
		ViewportDeathHUD();
	}
}

void ANPC_Enemy::ViewportDeathHUD()
{
	GameMode = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode());
	GameMode->ChangeHUDState(EHUDState::HUD_Death);
}

void ANPC_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

