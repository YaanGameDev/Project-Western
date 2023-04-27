#include "WallDestroyProjectile.h"

//Engine
#include "Components/BoxComponent.h"

//Project
#include "Projectile.h"

// Sets default values
AWallDestroyProjectile::AWallDestroyProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DestroyProjectile = CreateDefaultSubobject<UBoxComponent>(FName("CollisionDestroyProjectile"));
	RootComponent = DestroyProjectile;

	DestroyProjectile->OnComponentBeginOverlap.AddDynamic(this, &AWallDestroyProjectile::DestroyProjectileCollision);

}

// Called when the game starts or when spawned
void AWallDestroyProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWallDestroyProjectile::DestroyProjectileCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Projectile = Cast<AProjectile>(OtherActor);
	if (IsValid(Projectile))
	{
		Projectile->Destroy();
	}
}

// Called every frame
void AWallDestroyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

