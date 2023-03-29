// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Enemy.h"

//Engine
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

//Project
#include "CharacterRunner.h"
#include "Projectile.h"
#include "MainGameModeBase.h"

// Sets default values
ANPC_Enemy::ANPC_Enemy()
{
	SkeletalMeshNPC = CreateDefaultSubobject<USkeletalMeshComponent>(FName("SkeletalMeshNPC"));
	RootComponent = SkeletalMeshNPC;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollision"));
	BoxCollision->SetupAttachment(SkeletalMeshNPC);

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
	ACharacterRunner* CharacterRunner = Cast<ACharacterRunner>(OtherActor);
	if (IsValid(CharacterRunner))
	{
		CharacterRunner->Destroy();
		ViewportDeathHUD();
		return;
	}
}

void ANPC_Enemy::ViewportDeathHUD()
{
	GameMode = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode());
	GameMode->ChangeHUDState(EHUDState::HUD_Death);
}

