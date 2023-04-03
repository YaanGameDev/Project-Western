// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnEnemy.generated.h"

class ANPC_Enemy;
class AEnemyObstacle;
class AHostileEntity;

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

	// Spawn Actor ( Enemy - Obstacle )

	AEnemyObstacle* Obstacle;

	UPROPERTY(EditAnywhere, Category = "SpawnEnemy")
		TSubclassOf<AHostileEntity> SpawnEnemy;

	UFUNCTION()
		void ObstacleEnemyLocation();

	// Variable for rand range

	UPROPERTY(EditAnywhere)
		float minSpawnTime = 1;

	UPROPERTY(EditAnywhere)
		float maxSpawnTime = 5;

};
