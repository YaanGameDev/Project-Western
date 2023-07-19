// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Floor.generated.h"

class AMainGameModeBase;
class ACharacterRunner;

UCLASS()
class PROJECTWESTERN_API AFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloor();

	UPROPERTY(EditAnywhere, Category = "ConfigsProcedural")
		class USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, Category = "ConfigsProcedural")
		class UStaticMeshComponent* Floor;

	UPROPERTY(EditAnywhere, Category = "ConfigsProcedural")
		class UArrowComponent* AttachPoint;

	FORCEINLINE const FTransform& GetAttachTransform() const
	{
		return AttachPoint->GetComponentTransform();
	}

	UPROPERTY(EditAnywhere, Category = "ConfigsProcedural")
		class UBoxComponent* TriggerBox;

	UFUNCTION()
		void BeginTriggerBox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UPROPERTY()
	AMainGameModeBase* GameMode;

	UPROPERTY()
	ACharacterRunner* CharacterRunner;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
