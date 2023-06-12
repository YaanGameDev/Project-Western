
// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Enemy.h"

//Engine
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

//Project
#include "CharacterRunner.h"
#include "MainGameModeBase.h"
#include "Projectile.h"

// Sets default values
ANPC_Enemy::ANPC_Enemy()
{
	PrimaryActorTick.bCanEverTick = true;

	NPC_Enemy = CreateDefaultSubobject<USkeletalMeshComponent>(FName(TEXT("StaticMesh")));
	NPC_Enemy->SetRelativeRotation(FRotator3d(0.f, -90.f, 0.f));
	NPC_Enemy->SetRelativeLocation(FVector(0.f, 0.f, -15.f));
	RootComponent = NPC_Enemy;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(FName(TEXT("BoxCollision")));
	BoxCollision->SetupAttachment(NPC_Enemy);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ANPC_Enemy::BeginCollisionNPCEnemy);
}

void ANPC_Enemy::DestroyEnemy()
{
	if (IsValid(this))
	{
		this->Destroy();
	}
}

// Called when the game starts or when spawned
void ANPC_Enemy::BeginPlay()
{
	Super::BeginPlay();
}

void ANPC_Enemy::BeginCollisionNPCEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CharacterRunner = Cast<ACharacterRunner>(OtherActor);
	if (IsValid(CharacterRunner) && CharacterRunner->GetPlayerState() != EStateAnimationsPlayer::Death && GetPlayerState() != EStateEnemy::Death)
	{
		CharacterRunner->DeathFunction();
	}
}

void ANPC_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANPC_Enemy::DeathFunction()
{
	SetNewPlayerState(EStateEnemy::Death);
	GetWorldTimerManager().SetTimer(TimerEnemyDestroy, this, &ANPC_Enemy::DestroyEnemy, TimerDestroy, false);
}

EStateEnemy ANPC_Enemy::GetPlayerState()
{
	return currentPlayerState;
}

void ANPC_Enemy::SetNewPlayerState(EStateEnemy newState)
{
	PreviousPlayerState = currentPlayerState;
	currentPlayerState = newState;
}

EStateEnemy ANPC_Enemy::GetPreviousPlayerState()
{
	return PreviousPlayerState;
}

