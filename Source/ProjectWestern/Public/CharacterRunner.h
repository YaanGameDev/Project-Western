// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterRunner.generated.h"

class ACharacterRunner;
class AWeapon;
class AMainGameModeBase;
class AProjectile;

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
	AMainGameModeBase* GameMode;

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

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSoftClassPtr<class AWeapon> WeaponClass;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* CameraPlayer;
	
	
	//Fire Projectile
	void FireProjectile();

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSoftClassPtr<class AProjectile> ProjectileClass;


};