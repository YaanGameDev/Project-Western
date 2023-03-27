// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class ANPC_Enemy;

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

	ANPC_Enemy* Enemy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Projectile;

	UPROPERTY(EditAnywhere)
		class USphereComponent* CollisionProjectile;

	UFUNCTION()
		void BeginCollisionProjectile(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	
};
