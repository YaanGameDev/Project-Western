// Fill out your copyright notice in the Description page of Project Settings.

//Engine
#include "AudioAnimNotify.h"

//Project
#include "CharacterRunner.h"

void UAudioAnimNotify::Notify(USkeletalMeshComponent* meshComp, UAnimSequenceBase* audio, const FAnimNotifyEventReference& eventReference)
{
	Super::Notify(meshComp, audio, eventReference);

	ACharacterRunner* CharacterRunner = Cast<ACharacterRunner>(meshComp->GetOwner());

	if (IsValid(CharacterRunner))
	{
		CharacterRunner->FireWeapon();
	}
}
