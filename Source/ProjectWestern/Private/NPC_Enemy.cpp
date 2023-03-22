// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Enemy.h"

//Engine
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

//Project
#include "CharacterRunner.h"

// Sets default values
ANPC_Enemy::ANPC_Enemy()
{
	SkeletalMeshNPC = CreateDefaultSubobject<USkeletalMeshComponent>(FName("SkeletalMeshNPC"));
	RootComponent = SkeletalMeshNPC;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollision"));
	BoxCollision->SetupAttachment(SkeletalMeshNPC);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ANPC_Enemy::BeginCollisionNPCEnemy);

}

// Called when the game starts or when spawned
void ANPC_Enemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANPC_Enemy::BeginCollisionNPCEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CharacterRunner = Cast<ACharacterRunner>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (IsValid(CharacterRunner))
	{
		CharacterRunner->Destroy();
	}
	
}

