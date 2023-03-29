// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnEnemy.generated.h"

class ANPC_Enemy;

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

	//Spawn Actor (Enemy)
	UPROPERTY()
	ANPC_Enemy* Enemy;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* SpawnEnemyLocation;
	
	UPROPERTY(EditAnywhere, Category = "SpawnEnemy")
		TSubclassOf<ANPC_Enemy>SpawnEnemy;

	UFUNCTION()
		void SpawnActor();
	
};
