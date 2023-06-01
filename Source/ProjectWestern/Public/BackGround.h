// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackGround.generated.h"

UCLASS()
class PROJECTWESTERN_API ABackGround : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABackGround();

	// Moving Background Map
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
		FVector VelocityBackground = { 0,0,0 };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
