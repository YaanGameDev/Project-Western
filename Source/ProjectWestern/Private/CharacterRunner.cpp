// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterRunner.h"

//Engine
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

//Project
#include "Weapon.h"
#include "CharacterRunner.h"
#include "MainGameModeBase.h"
#include "Projectile.h"

// Sets default values
ACharacterRunner::ACharacterRunner()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
PrimaryActorTick.bCanEverTick = true;

CameraPlayer = CreateDefaultSubobject<UCameraComponent>(FName("Camera"));
CameraPlayer->SetRelativeLocation(FVector(0.0f, 570.0f, 0.0f));
CameraPlayer->SetupAttachment(RootComponent);

AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ACharacterRunner::BeginPlay()
{
	Super::BeginPlay();

	SpawnWithWeapon();

	GameMode = Cast<AMainGameModeBase>(GetWorld()->GetAuthGameMode());

}

void ACharacterRunner::AddCoin()
{
	GameMode->AddCoin();
}

void ACharacterRunner::PressShooting()
{
	isShooting = true;
	if (!IsValid(Weapon))
	{
		return;
	}
}

void ACharacterRunner::FireWeapon()
{
	if (isShooting)
	{
		if (IsValid(Weapon))
		{
			Weapon->SpawnProjectile({});
		}
	}
	isShooting = false;
}

void ACharacterRunner::SpawnWithWeapon()
{
	FActorSpawnParameters Parameters;
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Weapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass.LoadSynchronous(), FTransform(), Parameters);
	Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("hand_r_pickup"));
}

void ACharacterRunner::SetNewPlayerState(EStateAnimationsPlayer newState)
{
	PreviousPlayerState = currentPlayerState;
	currentPlayerState = newState;
}

EStateAnimationsPlayer ACharacterRunner::GetPlayerState()
{
	return currentPlayerState;
}

EStateAnimationsPlayer ACharacterRunner::GetPreviousPlayerState()
{
	return PreviousPlayerState;
}

// Called every frame
void ACharacterRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	switch (currentPlayerState)
	{
		case EStateAnimationsPlayer::Idle:
		{
			if (isShooting)
			{
				SetNewPlayerState(EStateAnimationsPlayer::Shooting);
			}
			break;
		}
		case EStateAnimationsPlayer::Jumping:
		{
			if(!GetCharacterMovement()->IsFalling())
			{
				SetNewPlayerState(EStateAnimationsPlayer::Idle);
			}
			if (isShooting)
			{
				if(GetCharacterMovement()->GetLastUpdateVelocity().Z > 0)
				{
					SetNewPlayerState(EStateAnimationsPlayer::Jumping);
			}
				}
			break;
		}
		case EStateAnimationsPlayer::Shooting:
		{
			if (!isShooting)
			{
				SetNewPlayerState(EStateAnimationsPlayer::Idle);
			}
			break;
		}
		case EStateAnimationsPlayer::Death:
		{
		}
	}

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (RunningVelocity * GameMode->CurrentDifficultyFactor) * DeltaTime;
	SetActorLocation(CurrentLocation);

}

// Called to bind functionality to input
void ACharacterRunner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterRunner::PlayerJump);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ACharacterRunner::PressShooting);
}

void ACharacterRunner::DeathFunction_Implementation()
{
	SetNewPlayerState(EStateAnimationsPlayer::Death);
	GetCharacterMovement()->DisableMovement();
	GetWorldTimerManager().SetTimer(TimerPauseGame, this, &ACharacterRunner::SetGamePaused, 3.5f, false);
	
}

void ACharacterRunner::PlayerJump()
{
	if (currentPlayerState == EStateAnimationsPlayer::Idle)
	{
		GetCharacterMovement()->JumpZVelocity = JumpVelocity;
		Jump();
	}
}

void ACharacterRunner::SetGamePaused()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}


