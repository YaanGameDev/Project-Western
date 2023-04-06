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

void ACharacterRunner::AddCoin()
{
	GameMode->AddCoin();
}

// Called when the game starts or when spawned
void ACharacterRunner::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters Parameters;
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Weapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass.LoadSynchronous(), FTransform(), Parameters);
	Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("hand_r_pickup"));

	GameMode = Cast<AMainGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	check(GameMode);
}

void ACharacterRunner::FireProjectile()
{
	if (IsValid(Weapon))
	{
		Weapon->SpawnProjectile({});
	}
	IsShooting = false;
}

void ACharacterRunner::ShootingTrue()
{
	if (IsValid(Weapon))
	{
		return;
	}
	IsShooting = true;
}

// Called every frame
void ACharacterRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterRunner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterRunner::PlayerJump);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ACharacterRunner::ShootingTrue);
	InputComponent->BindAction("Fire", IE_Released, this, & ACharacterRunner::FireProjectile);
}

void ACharacterRunner::PlayerJump()
{
	GetCharacterMovement()->JumpZVelocity = JumpVelocity;
	Jump();
}



