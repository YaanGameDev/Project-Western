// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC_Enemy.generated.h"

class AMainGameModeBase;

UCLASS()
class PROJECTWESTERN_API ANPC_Enemy : public AActor
{
	GENERATED_BODY()
	
public:	
	ANPC_Enemy();

	//Calling actors
	AMainGameModeBase* GameMode;

	// Variables for add health in Enemy
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
		float Health;

	UFUNCTION()
		void SetHealth(float Dano);

	UFUNCTION()
		float GetHealth();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "VelocityEnemy")
		FVector VelocityEnemy = { 0,0,0 };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollision;

private:
	//Collision Destroy Player
	UFUNCTION()
		void BeginCollisionNPCEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void ViewportDeathHUD();
};
