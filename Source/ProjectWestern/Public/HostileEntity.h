// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HostileEntity.generated.h"

class AMainGameModeBase;

UCLASS()
class PROJECTWESTERN_API AHostileEntity : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHostileEntity();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "VelocityEnemy")
		FVector Velocity = { 0,0,0 };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	AMainGameModeBase* GameMode;
};
