// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterRunner.generated.h"

class ACharacterRunner;
class AWeapon;

UCLASS()
class PROJECTWESTERN_API ACharacterRunner : public ACharacter
{

	GENERATED_BODY()

public:
	ACharacterRunner();

	//Calling Actors
	UPROPERTY()
	ACharacterRunner* CharacterRunner;

	UPROPERTY()
	AWeapon* Weapon;

	//Player Run
	void RunAutomatic();
	float RunSpeedPlayer = 50;

	//Player Jump
	void PlayerJump();
	UPROPERTY(EditDefaultsOnly, Category = "SettingJumpVelocity");
	float JumpVelocity = 0;

	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
		TSubclassOf<class AWeapon> WeaponClass;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* CameraPlayer;
	
	



};