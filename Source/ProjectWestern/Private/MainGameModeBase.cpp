#include "MainGameModeBase.h"

//Engine
#include "Blueprint/UserWidget.h"
#include "Kismet/GamePlayStatics.h"

//Project
#include "InGameBaseWidget.h"
#include "EnemyObstacle.h"
#include "CharacterRunner.h"

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
			ApplyHUD(MainMenuHUDClass, false, false);
			break;
		}
		case EHUDState::HUD_InGame:
		{
			ApplyHUD(InGameHUDClass, false, false);
			break;
		}
		case EHUDState::HUD_PauseGame:
		{
			ApplyHUD(PauseGameHUDClass, false, false);
			break;
		}
		case EHUDState::HUD_Death:
		{
			ApplyHUD(DeathHUDClass, true, true);
			break;
		}
		case EHUDState::HUD_Credits:
		{
			ApplyHUD(CreditsHUDClass, true, true);
			break;
		}
		case EHUDState::HUD_Shop:
		{
			ApplyHUD(ShopHUDClass, true, true);
			break;
		}
		case EHUDState::HUD_Tutorial:
		{
			ApplyHUD(TutorialHUDClass, true, true);
			break;
		}
			default:
			{
				ApplyHUD(MainMenuHUDClass, false, false);
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

bool AMainGameModeBase::ApplyHUD(TSubclassOf<class UUserWidget> WidgetToApply, bool bShowMouseCursor, bool EnableClickEvents)
{
	APlayerController* MyController = GetWorld()->GetFirstPlayerController();

	if (WidgetToApply != nullptr)
	{
		if (IsValid(CurrentWidget))
		{
			MyController->bShowMouseCursor = bShowMouseCursor;
			MyController->bEnableClickEvents = EnableClickEvents;

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

	UpdateDifficulty();
}

void AMainGameModeBase::AddEnemies()
{
	TotalEnemies += 1;
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


