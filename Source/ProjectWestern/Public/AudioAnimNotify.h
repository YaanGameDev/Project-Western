// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AudioAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTWESTERN_API UAudioAnimNotify : public UAnimNotify
{
	GENERATED_BODY()
	
public:

	virtual void Notify(USkeletalMeshComponent* meshComp, UAnimSequenceBase* Audio, const FAnimNotifyEventReference& eventReference) override;
};
