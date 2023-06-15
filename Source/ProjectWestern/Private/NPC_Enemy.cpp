
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



// Called when the game starts or when spawned
void ANPC_Enemy::BeginPlay()
{
	Super::BeginPlay();
	SetNewEnemyState(EStateEnemy::Running);
}

void ANPC_Enemy::BeginCollisionNPCEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CharacterRunner = Cast<ACharacterRunner>(OtherActor);
	if (IsValid(CharacterRunner) && CharacterRunner->GetPlayerState() != EStateAnimationsPlayer::Death && GetEnemyState() != EStateEnemy::Death)
	{
		CharacterRunner->DeathFunction();
	}
}

void ANPC_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANPC_Enemy::EnemyDeathFunction()
{
	SetNewEnemyState(EStateEnemy::Death);
	UKismetSystemLibrary::PrintString(this, FString(__FUNCTION__));
	GetWorldTimerManager().SetTimer(TimerEnemyDestroy, this, &ANPC_Enemy::DestroyEnemy, TimerDestroy, false);
	
}

void ANPC_Enemy::SetNewEnemyState(EStateEnemy newEnemyState)
{
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("previous = %d, current = %d"), currentEnemyState, newEnemyState));
	PreviousEnemyState = currentEnemyState;
	currentEnemyState = newEnemyState;
}

EStateEnemy ANPC_Enemy::GetEnemyState()
{
	return currentEnemyState;
}

EStateEnemy ANPC_Enemy::GetPreviousEnemyState()
{
	return PreviousEnemyState;
}

void ANPC_Enemy::DestroyEnemy()
{
	if (IsValid(this))
	{
		this->Destroy();
		UKismetSystemLibrary::PrintString(this, FString(__FUNCTION__));
	}	
}
