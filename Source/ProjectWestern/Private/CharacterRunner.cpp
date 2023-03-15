// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterRunner.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"

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
	
}

// Called every frame
void ACharacterRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddMovementInput(GetActorForwardVector() * DeltaTime * RunSpeedPlayer);

}

// Called to bind functionality to input
void ACharacterRunner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterRunner::PlayerJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacterRunner::StopPlayerJump);

}

void ACharacterRunner::PlayerJump()
{
	IsJumping = true;
	if (IsJumping)
	{
		GetCharacterMovement()->AirControl = 20.f;
		GetCharacterMovement()->JumpZVelocity = 425.f;
		GetCharacterMovement()->GravityScale = 1.5f;
	}
	Jump();
}

void ACharacterRunner::StopPlayerJump()
{
	IsJumping = false;
}

