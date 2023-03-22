// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC_Enemy.generated.h"

class ACharacterRunner;

UCLASS()
class PROJECTWESTERN_API ANPC_Enemy : public AActor
{
	GENERATED_BODY()
	
public:	
	ANPC_Enemy();

	//Calling Actors
	ACharacterRunner* CharacterRunner;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//SkeletalMesh
	UPROPERTY(EditAnywhere)
		class USkeletalMeshComponent* SkeletalMeshNPC;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollision;
	

private:
	//Collision Destroy Player
	UFUNCTION()
		void BeginCollisionNPCEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
