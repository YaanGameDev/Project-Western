// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HostileEntity.h"
#include "NPC_Enemy.generated.h"

class ACharacterRunner;
class AMainGameModeBase;

UCLASS()
class PROJECTWESTERN_API ANPC_Enemy : public AHostileEntity
{
	GENERATED_BODY()
	
public:	
	ANPC_Enemy();

	// Variables for add health in Enemy
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
		float Health;

	UFUNCTION()
		void SetHealth(float Dano);

	UFUNCTION()
		float GetHealth();

	virtual void Tick(float DeltaTime) override;

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
	
	UFUNCTION()
		void ViewportDeathHUD();

	UPROPERTY()
		ACharacterRunner* CharacterRunner;

	UPROPERTY()
		AMainGameModeBase* GameMode;
};
