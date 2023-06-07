// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleportingBackground.generated.h"

class ABackgroundElement;

UCLASS()
class PROJECTWESTERN_API ATeleportingBackground : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleportingBackground();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
		class UBoxComponent* WallTeleportBackground;

	UPROPERTY(EditDefaultsOnly)
		class USphereComponent* RespawnLocation;

	FVector RespawnTarget;


	UFUNCTION()
		void BeginWallTeleporting(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY()
		ABackgroundElement* BackGround;
};
