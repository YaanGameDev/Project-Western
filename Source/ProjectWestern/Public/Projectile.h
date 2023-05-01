// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class ANPC_Enemy;
class ACharacterRunner;
class AMainGameModeBase;

UCLASS()
class PROJECTWESTERN_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();

	virtual void Tick(float DeltaTime) override;

	//Forward Projectile
	UPROPERTY(EditAnywhere)
		float VelocityProjectile = 0;

	//Code for kill enemies count
	UFUNCTION(BlueprintCallable)
		void AddEnemies();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int32 TotalEnemies = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Projectile;

	UPROPERTY(EditAnywhere)
		class USphereComponent* CollisionProjectile;

	UFUNCTION(BlueprintCallable)
		void BeginCollisionProjectile(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	//Calling actors
	UPROPERTY()
		ANPC_Enemy* Enemy;

	UPROPERTY()
		ACharacterRunner* Character;

};
