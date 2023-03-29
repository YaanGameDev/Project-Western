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
