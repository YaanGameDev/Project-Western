// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Train.generated.h"

UCLASS()
class PROJECTWESTERN_API ATrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrain();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent* TrainMesh;

	UPROPERTY(EditDefaultsOnly, Category = "ConfigsVelocity")
		FVector VelocityTrain = { 0,0,0 };



};
