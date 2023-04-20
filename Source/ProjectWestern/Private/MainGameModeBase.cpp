#include "MainGameModeBase.h"

//Engine
#include "Blueprint/UserWidget.h"
#include "Kismet/GamePlayStatics.h"

//Project
#include "InGameBaseWidget.h"
#include "EnemyObstacle.h"

void AMainGameModeBase::BeginPlay()
{
	ApplyHUDChanges();
}

AMainGameModeBase::AMainGameModeBase()
{
	HUDState = EHUDState::HUD_MainMenu;
}

void AMainGameModeBase::ApplyHUDChanges()
{
	switch (HUDState)
	{
		case EHUDState::HUD_MainMenu:
		{
			ApplyHUD(MainMenuHUDClass);
			break;
		}
		case EHUDState::HUD_InGame:
		{
			ApplyHUD(InGameHUDClass);
			break;
		}
		case EHUDState::HUD_PauseGame:
		{
			ApplyHUD(PauseGameHUDClass);
			break;
		}
		case EHUDState::HUD_Death:
		{
			ApplyHUD(DeathHUDClass);
			break;
		}
			default:
			{
				ApplyHUD(MainMenuHUDClass);
					break;
			}
	}
}

EHUDState AMainGameModeBase::GetHUDState()
{
	return HUDState;
}


void AMainGameModeBase::ChangeHUDState(EHUDState newState)
{
	HUDState = newState;
	ApplyHUDChanges();
}

bool AMainGameModeBase::ApplyHUD(TSubclassOf<class UUserWidget> WidgetToApply)
{
	APlayerController* MyController = GetWorld()->GetFirstPlayerController();

	if (WidgetToApply != nullptr)
	{
		if (IsValid(CurrentWidget))
		{
			CurrentWidget->RemoveFromParent();
		}
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetToApply);

		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
			return true;
		}
		return false;
	}
	 return	false;
}

void AMainGameModeBase::AddCoin()
{
	TotalCoins += 1;

	auto* InGameWidget = Cast<UInGameBaseWidget>(CurrentWidget);
	if (IsValid(InGameWidget))
	{
		InGameWidget->SetCoinsCount(TotalCoins);
	}
	UpdateDifficulty();
}

void AMainGameModeBase::UpdateDifficulty()
{
	if (TotalCoins % 50 == 0)
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
