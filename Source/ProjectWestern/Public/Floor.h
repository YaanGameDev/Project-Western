// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Floor.generated.h"

class AMainGameModeBase;
class ACharacterRunner;

UCLASS()
class PROJECTWESTERN_API AFloor : public AFloor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloor();
		
	UPROPERTY()
	AMainGameModeBase* GameMode;

	UPROPERTY()
		ACharacterRunner* CharacterRunner;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* AttachPoint;

	FORCEINLINE const FTransform& GetAttachTransform() const
	{
		return AttachPoint->GetComponentTransform();
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
		class UStaticMeshComponent* Floor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
		class UBoxComponent* BoxCollision;

	UFUNCTION()
		void BeginBoxCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void DestroyFloor();

	UPROPERTY(EditDefaultsOnly, Category = "ConfigsProcedural")
		FTimerHandle TimerDestroyFloor;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
