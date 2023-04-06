// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerTest.generated.h"


class AMainGameModeBase;

UCLASS()
class PROJECTWESTERN_API APlayerTest : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoverPlayerWS(float Valor);

	UFUNCTION()
		void MoverPlayerAD(float Valor);
	
	AMainGameModeBase* GameMode;
	

};
