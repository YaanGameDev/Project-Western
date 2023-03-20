// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterRunner.generated.h"

UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	STATE_Run,
	STATE_Jump
};


UCLASS()
class PROJECTWESTERN_API ACharacterRunner : public ACharacter
{

	GENERATED_BODY()

public:
	ACharacterRunner();
	

	//State Machine
	EPlayerState currentPlayerState;

	EPlayerState PreviousPlayerState;

	UFUNCTION(BlueprintCallable)
		void SetNewPlayerState(EPlayerState newState);

	UFUNCTION(BlueprintPure)
		EPlayerState GetPlayerState() const;

	UFUNCTION()
		void HandleStateEnd();

	UFUNCTION()
		void HandleStateEntered();


protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	UPROPERTY(EditAnywhere)
		class UCameraComponent* CameraPlayer;

public:

	//Player Run
	void RunAutomatic();
	float RunSpeedPlayer = 50;

	//Player Jump
	void PlayerJump();
	UPROPERTY(EditAnywhere, Category = "SettingJumpVelocity");
		float JumpVelocity = 0;



};