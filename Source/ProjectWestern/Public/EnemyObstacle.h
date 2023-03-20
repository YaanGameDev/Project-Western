// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyObstacle.generated.h"

class ACharacterRunner;
UCLASS()
class PROJECTWESTERN_API AEnemyObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* MeshEnemy;

	UPROPERTY(EditAnywhere)
		class USphereComponent* SphereCollisionEnemy;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	//Calling Actors
	ACharacterRunner* CharacterRunner;
};
