// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterRunner.generated.h"

UCLASS()
class PROJECTWESTERN_API ACharacterRunner : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterRunner();

	UPROPERTY(EditAnywhere)
		class UCameraComponent* CameraPlayer;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float RunSpeedPlayer = 50;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//Player Jump
	void PlayerJump();

	void StopPlayerJump();

	UPROPERTY(BlueprintReadWrite)
	bool IsJumping;

	//Variable set value for animation
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ValueAnimation = 0.1;
};
