// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"

#include "MainGameModeBase.generated.h"

class UUserWidget;
class AHostileEntity;

UENUM(BlueprintType)
enum class EHUDState : uint8
{
	HUD_MainMenu,
	HUD_InGame,
	HUD_PauseGame,
	HUD_Death
};

/**
 * 
 */
UCLASS()

class PROJECTWESTERN_API AMainGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

public:
	AMainGameModeBase();

	void ApplyHUDChanges();

	EHUDState GetHUDState();

	UFUNCTION(BlueprintCallable, Category = "HUD Functions")
	void ChangeHUDState(EHUDState newState);


	bool ApplyHUD(TSubclassOf<UUserWidget> WidgetToApply, bool bShowMouseCursor, bool EnableClickEvents);


	UFUNCTION(BlueprintCallable)
		void AddCoin();

	UPROPERTY(VisibleAnywhere)
		int32 TotalCoins = 0;


	//UpdateDifficulty
	UFUNCTION()
		void UpdateDifficulty();

	UPROPERTY(EditDefaultsOnly)
		double DifficultyCoeficion = 0.2;

	double GetCurrentDificulty();

	double CurrentDifficultyFactor = 1;

	static AMainGameModeBase* GetGameMode(UObject* WorldObject);

protected:
	EHUDState HUDState;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDWidget", Meta = (BlueprintProtected = "true"))
		TSubclassOf<UUserWidget> MainMenuHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDWidget", Meta = (BlueprintProtected = "true"))
		TSubclassOf<UUserWidget> InGameHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDWidget", Meta = (BlueprintProtected = "true"))
		TSubclassOf<UUserWidget> PauseGameHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDWidget", Meta = (BlueprintProtected = "true"))
		TSubclassOf<UUserWidget> DeathHUDClass;

	UPROPERTY()
	UUserWidget* CurrentWidget;
};
