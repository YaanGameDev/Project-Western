// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coins.generated.h"

class ACharacterRunner;
class APlayerTest;

UCLASS()
class PROJECTWESTERN_API ACoins : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoins();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class USphereComponent* CollisionCoins;

	UFUNCTION()
		void BeginCollisionCoins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool Collided;

private:
	UPROPERTY()
	ACharacterRunner* Character;

	UPROPERTY()
	APlayerTest* PlayerTest;
};
