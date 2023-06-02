// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackgroundElement.generated.h"

class AMainGameModeBase;

UCLASS()
class PROJECTWESTERN_API ABackgroundElement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABackgroundElement();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "VelocityBackGround")
		FVector VelocityBackGround = {0,0,0};

	FVector SpawnLocation;

	FVector StartLocation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		double TargetDistance = 10;

	UPROPERTY()
		AMainGameModeBase* GameMode;

};
