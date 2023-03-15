// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"
#include "UnrealWidgetFwd.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GamePlayStatics.h"

void AMainGameModeBase::BeginPlay()
{
	ApplyHUDChanges();
}

AMainGameModeBase::AMainGameModeBase()
	: Super()
{
	HUDState = EHUDState::HUD_MainMenu;
}

void AMainGameModeBase::ApplyHUDChanges()
{
	if (CurrentWidget != nullptr)
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
			ApplyHUD(InGameHUDClass, false, false);
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

uint8 AMainGameModeBase::GetHUDState()
{
	return HUDState;
}

void AMainGameModeBase::ChangeHUDState(uint8 newState)
{
	HUDState = newState;
	ApplyHUDChanges();
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
		else return false;
	}
	else return	false;
}
