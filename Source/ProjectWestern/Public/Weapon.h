// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class ACharacterRunner;

UCLASS()
class PROJECTWESTERN_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	ACharacterRunner* CharacterRunner;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* MeshWeapon;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
