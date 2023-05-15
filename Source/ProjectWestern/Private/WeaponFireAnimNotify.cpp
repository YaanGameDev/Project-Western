// Fill out your copyright notice in the Description page of Project Settings.

//Engine
#include "WeaponFireAnimNotify.h"

//Project
#include "CharacterRunner.h"

void UWeaponFireAnimNotify::Notify(USkeletalMeshComponent* meshComp, UAnimSequenceBase* animation, const FAnimNotifyEventReference& eventReference)
{
	Super::Notify(meshComp, animation, eventReference);

	ACharacterRunner* CharacterRunner = Cast<ACharacterRunner>(meshComp->GetOwner());

	if (IsValid(CharacterRunner))
	{
		CharacterRunner->FireWeapon();
	}
}
