// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnEnemy.generated.h"

class ANPC_Enemy;
class AEnemyObstacle;

UCLASS()
class PROJECTWESTERN_API ASpawnEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnEnemy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Spawn Enemy Location
	UPROPERTY(EditAnywhere)
		class UBoxComponent* SpawnEnemyLocation;

	//Spawn Actor (Enemy - NPC)
	UPROPERTY()
	ANPC_Enemy* NPCEnemy;

	UPROPERTY(EditAnywhere, Category = "SpawnEnemy")
		TSubclassOf<ANPC_Enemy>SpawnNPC;

	//Spawn Actor ( Enemy - Obstacle )

	UPROPERTY()
	AEnemyObstacle* Obstacle;

	UPROPERTY(EditAnywhere, Category = "SpawnEnemy")
		TSubclassOf<AEnemyObstacle> SpawnObstacle;

	UFUNCTION()
		void ObstacleEnemyLocation();

	UPROPERTY(EditAnywhere)
		float Spawn1 = 0;

	UPROPERTY(EditAnywherE)
		float Spawn2 = 0;
	//Test
	void SpawnEntity();	
};
