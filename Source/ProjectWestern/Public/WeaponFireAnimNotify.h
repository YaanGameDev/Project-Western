// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "WeaponFireAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTWESTERN_API UWeaponFireAnimNotify : public UAnimNotify
{
	GENERATED_BODY()
	

public:

	virtual void Notify(USkeletalMeshComponent* meshComp, UAnimSequenceBase* animation, const FAnimNotifyEventReference& eventReference) override;
};
