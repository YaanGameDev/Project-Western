// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SettingsCoin.generated.h"

class ACoins;

UCLASS()
class PROJECTWESTERN_API ASettingsCoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASettingsCoin();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void FunctionSpawnCoins();

	UPROPERTY(EditAnywhere)
		float minTimeSpawn = 0;

	UPROPERTY(EditAnywhere)
		float maxTimeSpawn = 0;

	ACoins* Coin;

	UPROPERTY(EditAnywhere, Category = "Coins")
		TSubclassOf<ACoins>SpawnCoins;

	UPROPERTY(EditAnywhere)
		class USphereComponent* SpawnCoinsLocation;

};
