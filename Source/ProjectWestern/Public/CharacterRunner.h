// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterRunner.generated.h"

class ACharacterRunner;
class AWeapon;
class AMainGameModeBase;
class AProjectile;

UENUM(BlueprintType)
enum class EStateAnimationsPlayer : uint8
{
	Idle,
	Jumping,
	Shooting,
	Death
};

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

	UPROPERTY()
		AMainGameModeBase* GameMode;

	//Code for Coins Collect
	UFUNCTION()
		void AddCoin();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int32 TotalCoins = 0;

	//End Code for Coins Collect
	
	//Player Death
	UFUNCTION(BlueprintNativeEvent)
	void DeathFunction();
	
	//Player Jump
	void PlayerJump();

	UPROPERTY(EditDefaultsOnly, Category = "SettingJumpVelocity")
	float JumpVelocity = 0;


	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	//Components Character
	UPROPERTY(EditAnywhere)
		class UCameraComponent* CameraPlayer;
	
	
	//Fire Projectile
	void ShootingFalse();

	void PressShooting();

	void FireWeapon();



	FTimerHandle TimerFireProjectile;

	//Timer Shooting
	UPROPERTY(EditDefaultsOnly, Category = "Timer Shooting")
		float ShootingTimer = 2;

	FTimerHandle TimerShooting;

	UPROPERTY(BlueprintReadWrite)
	bool isShooting;

	bool CanShooting = true;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSoftClassPtr<class AWeapon> WeaponClass;


	//State Animations for Player
	EStateAnimationsPlayer currentPlayerState;

	EStateAnimationsPlayer PreviousPlayerState;

	UFUNCTION(BlueprintCallable)
		void SetNewPlayerState(EStateAnimationsPlayer newState);

	UFUNCTION(BlueprintPure)
		EStateAnimationsPlayer GetPlayerState();

	UFUNCTION(BlueprintPure)
		EStateAnimationsPlayer GetPreviousPlayerState();


	


};