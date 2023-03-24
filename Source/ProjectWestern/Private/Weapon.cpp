#include "Weapon.h"

//Engine
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

//Project
#include "CharacterRunner.h"
#include "Projectile.h"

// Sets default values
AWeapon::AWeapon()
{
	MeshWeapon = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshWeapon"));
	RootComponent = MeshWeapon;

	ProjectileSpawn = CreateDefaultSubobject<USphereComponent>(FName("SpawnProjectile"));
	ProjectileSpawn->SetupAttachment(MeshWeapon);
}

void AWeapon::SpawnProjectile(const FRotator& projectileRotation)
{
	FActorSpawnParameters ParametersProjectile;
	ParametersProjectile.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector SpawnProjectile = ProjectileSpawn->GetComponentLocation();

	Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnProjectile, projectileRotation, ParametersProjectile);
	Projectile->AttachToActor(this, FAttachmentTransformRules::SnapToTargetIncludingScale, FName(NAME_None));
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();

}

