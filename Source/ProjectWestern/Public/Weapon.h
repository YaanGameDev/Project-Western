// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class ACharacterRunner;
class AProjectile;

UCLASS()
class PROJECTWESTERN_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	UPROPERTY()
	ACharacterRunner* CharacterRunner;

	UPROPERTY()
	AProjectile* Projectile;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* MeshWeapon;

	UPROPERTY(EditAnywhere)
		class USphereComponent* SphereSpawnProjectile;


	//SpawnProjectile
	void SpawnProjectile(const FRotator& projectileRotation);

	UPROPERTY(EditAnywhere, Category = Weapon)
		TSubclassOf<AProjectile> ProjectileClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
