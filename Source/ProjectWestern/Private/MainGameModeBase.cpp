#include "MainGameModeBase.h"

//Engine
#include "UnrealWidgetFwd.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GamePlayStatics.h"

//Project
#include "InGameBaseWidget.h"

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
	if (IsValid(CurrentWidget))
	{	
		CurrentWidget->RemoveFromParent();
	}

	switch (HUDState)
	{
		case EHUDState::HUD_MainMenu:
		{
			ApplyHUD(MainMenuHUDClass, true, true);
			break;
		}
		case EHUDState::HUD_InGame:
		{
			ApplyHUD(InGameHUDClass, true, true);
			break;
		}
		case EHUDState::HUD_PauseGame:
		{
			ApplyHUD(PauseGameHUDClass, true, true);
			break;
		}
		case EHUDState::HUD_Death:
		{
			ApplyHUD(DeathHUDClass, true, true);
			break;
		}
			default:
			{
				ApplyHUD(MainMenuHUDClass, true, true);
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

	APlayerController* MyController = GetWorld()->GetFirstPlayerController();
	if (HUDState == EHUDState::HUD_InGame)
	{
		FInputModeGameOnly GameOnly;
		MyController->SetInputMode(GameOnly);
	}
	else
	{
		FInputModeUIOnly UIOnly;
		MyController->SetInputMode(UIOnly);
	}
}

bool AMainGameModeBase::ApplyHUD(TSubclassOf<class UUserWidget> WidgetToApply, bool bShowMouseCursor, bool EnableClickEvents)
{
	APlayerController* MyController = GetWorld()->GetFirstPlayerController();

	if (WidgetToApply != nullptr)
	{
		MyController->bShowMouseCursor = bShowMouseCursor;
		MyController->bEnableClickEvents = EnableClickEvents;

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
}
