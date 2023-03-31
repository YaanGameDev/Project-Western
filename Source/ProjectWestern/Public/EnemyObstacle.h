// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyObstacle.generated.h"

class AMainGameModeBase;
class ACharacterRunner;
UCLASS()
class PROJECTWESTERN_API AEnemyObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyObstacle();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Calling Actors
	ACharacterRunner* CharacterRunner;
	AMainGameModeBase* GameMode;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* MeshEnemy;


	//Collision Destroy Enemy
	UPROPERTY(EditAnywhere)
		class USphereComponent* SphereCollisionEnemy;

	UFUNCTION()
	void BeginDestroyPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	void ViewportDeathHUD();

	UPROPERTY(EditAnywhere, Category = "VelocityObstacle")
		FVector VelocityObstacle = { 0,0,0 };
};
