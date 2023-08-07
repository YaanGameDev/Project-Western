#include "MainGameModeBase.h"

//Engine
#include "Blueprint/UserWidget.h"
#include "Kismet/GamePlayStatics.h"

//Project
#include "InGameBaseWidget.h"
#include "EnemyObstacle.h"
#include "CharacterRunner.h"
#include "Floor.h"

void AMainGameModeBase::BeginPlay()
{
	CreateInitialFloor();

}

void AMainGameModeBase::AddCoin()
{
	TotalCoins += CoinsValue;

	UpdateDifficulty();
}

void AMainGameModeBase::AddEnemies()
{
	TotalEnemies += 1;
}

void AMainGameModeBase::UpdateDifficulty()
{
	if (TotalCoins % CoinsIncrement == 0)
	{
		CurrentDifficultyFactor = GetCurrentDifficulty();
	}
}

double AMainGameModeBase::GetCurrentDifficulty()
{
	return TotalCoins * DifficultyCoeficion + 1;
}

AMainGameModeBase* AMainGameModeBase::GetGameMode(UObject* WorldObject)
{
	return WorldObject->GetWorld()->GetAuthGameMode<AMainGameModeBase>();
}

void AMainGameModeBase::CreateInitialFloor()
{
	for (int i = 0; i < InitialNumFloor; i++)
	{
		AddFloor();

	}
}

AFloor* AMainGameModeBase::AddFloor()
{
	UWorld* World = GetWorld();

	if (World)
	{
		TSubclassOf<AFloor> ChoiceClass = GetRandomFloorTile();
		if (ChoiceClass != nullptr)
		{
			AFloor* Floor = World->SpawnActor<AFloor>(ChoiceClass, NextSpawnPoint);
			if (Floor)
			{
				NextSpawnPoint = Floor->GetAttachTransform();
				return Floor;
			}
		}
	}
	return nullptr;
}

TSubclassOf<AFloor> AMainGameModeBase::GetRandomFloorTile()
{
	if (PossibleChoices.IsEmpty())
	{
		return nullptr;
	}
	int RandomIndex = FMath::RandRange(0, PossibleChoices.Num() - 1);

	return PossibleChoices[RandomIndex];
}


