// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

//Engine
#include "Components/StaticMeshComponent.h"

//Project
#include "CharacterRunner.h"

// Sets default values
AWeapon::AWeapon()
{
	MeshWeapon = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshWeapon"));
	RootComponent = MeshWeapon;

	ConstructorHelpers::FObjectFinder<UStaticMesh>Revolvi(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));

	if (Revolvi.Succeeded())
	{
		MeshWeapon->SetStaticMesh(Revolvi.Object);
	}
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();

}

