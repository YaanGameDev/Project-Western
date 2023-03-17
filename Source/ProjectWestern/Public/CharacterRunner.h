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
	ACharacterRunner();


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

};