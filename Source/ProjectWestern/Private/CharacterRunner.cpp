// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterRunner.h"

//Engine
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"

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

	FActorSpawnParameters Parameters;
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Weapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass.LoadSynchronous(), FTransform(), Parameters);
	Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("hand_r_pickup"));
}

void ACharacterRunner::FireProjectile()
{
	if (IsValid(Weapon))
	{
		Weapon->SpawnProjectile({});
	}
}
	


// Called every frame
void ACharacterRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunAutomatic();

}

// Called to bind functionality to input
void ACharacterRunner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterRunner::PlayerJump);
	InputComponent->BindAction("Fire", IE_Pressed, this, & ACharacterRunner::FireProjectile);

}

void ACharacterRunner::RunAutomatic()
{
	AddMovementInput(GetActorForwardVector() * RunSpeedPlayer);
}

void ACharacterRunner::PlayerJump()
{
	GetCharacterMovement()->JumpZVelocity = JumpVelocity;
	Jump();
}



