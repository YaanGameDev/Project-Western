// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"

#include "MainGameModeBase.generated.h"

class UUserWidget;
class AHostileEntity;
class AFloor;

/**
 * 
 */
UCLASS()

class PROJECTWESTERN_API AMainGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

public:

	//Code for Collect Coins
	UFUNCTION(BlueprintCallable)
		void AddCoin();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int32 TotalCoins = 0;

	//Code for Kill enemies count
	UFUNCTION(BlueprintCallable)
		void AddEnemies();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int32 TotalEnemies = 0;

	//UpdateDifficulty
	UFUNCTION()
		void UpdateDifficulty();

	UPROPERTY(EditDefaultsOnly)
	double DifficultyCoeficion = 0.2;

	double GetCurrentDifficulty();

	double CurrentDifficultyFactor = 1;

	UPROPERTY(EditDefaultsOnly)
		int CoinsIncrement = 10;

	UPROPERTY(EditDefaultsOnly)
		int CoinsValue = 10;

	static AMainGameModeBase* GetGameMode(UObject* WorldObject);


	UPROPERTY(EditAnywhere, Category = "ConfigsProcedural")
		TArray<TSubclassOf<AFloor>>PossibleChoices;

	UFUNCTION()
		void CreateInitialFloor();

	UPROPERTY(EditAnywhere, Category = "ConfigsProcedural")
		int32 InitialNumFloor = 1;

	UFUNCTION()
		AFloor* AddFloor();

	UFUNCTION()
		TSubclassOf<AFloor> GetRandomFloorTile();

	UPROPERTY(VisibleInstanceOnly, Category = "ConfigsProcedural")
		FTransform NextSpawnPoint;

protected:
};
