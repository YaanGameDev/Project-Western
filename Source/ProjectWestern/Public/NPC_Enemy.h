// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HostileEntity.h"
#include "NPC_Enemy.generated.h"

class ACharacterRunner;
class AMainGameModeBase;

UENUM(BlueprintType)
enum class EStateEnemy : uint8
{
	Running = 0,
	Death
};

UCLASS()
class PROJECTWESTERN_API ANPC_Enemy : public AHostileEntity
{
	GENERATED_BODY()
	
public:	
	ANPC_Enemy();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void EnemyDeathFunction();

	UFUNCTION(BlueprintPure)
		EStateEnemy GetEnemyState();

	//State Animations for Player
	EStateEnemy currentEnemyState;

	EStateEnemy PreviousEnemyState;

	UFUNCTION(BlueprintCallable)
		void SetNewEnemyState(EStateEnemy newEnemyState);

	UFUNCTION(BlueprintPure)
		EStateEnemy GetPreviousEnemyState();

	UPROPERTY(EditAnywhere, Category = "Animations")
		TSubclassOf<UAnimSequence>Animation_Running;

	UPROPERTY(EditAnywhere, Category = "Animations")
		TSubclassOf<UAnimSequence>Animation_Death;

	FTimerHandle TimerEnemyDestroy;

	UPROPERTY(EditDefaultsOnly)
		float TimerDestroy = 0;

	void DestroyEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class USkeletalMeshComponent* NPC_Enemy;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollision;

	//Collision Destroy Player
	UFUNCTION(BlueprintCallable)
		void BeginCollisionNPCEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
private:

	UPROPERTY()
		ACharacterRunner* CharacterRunner;

	UPROPERTY()
		AMainGameModeBase* GameMode;
};
