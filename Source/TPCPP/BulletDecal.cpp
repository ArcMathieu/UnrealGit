// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletDecal.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABulletDecal::ABulletDecal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	canSpawnDecal = false;
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("BulletMesh");
	SetRootComponent(BulletMesh);

	BulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>("BulletMovement");
	BulletMovement->InitialSpeed = 5000.0f;
	BulletMovement->MaxSpeed = 5000.0f;

	//BulletMesh->OnComponentHit.AddDynamic(this, &ABulletDecal::OnHit);
}

// Called when the game starts or when spawned
void ABulletDecal::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABulletDecal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult HitResult;

	FVector StartTrace = this->GetActorLocation();
	FVector EndTrace = (Velocity * DeltaTime) + StartTrace;
	EndTrace.Z += this->GetActorRotation().Pitch;
	TimeAlpha--;
	FCollisionQueryParams CollisionParam;
	CollisionParam.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Destructible, CollisionParam)) 
	{
		if (HitResult.GetActor()) {
			if (!canSpawnDecal) 
			{
				TimeAlpha = 60 * 5;
				canSpawnDecal = true;
				ADecalActor* decal = GetWorld()->SpawnActor<ADecalActor>(HitResult.Location, FRotator());
				decal->SetDecalMaterial(BulletSplatTxt);
				decal->SetLifeSpan(5.0f);
				decal->GetDecal()->DecalSize = FVector(48.0f, 48.0f, 48.0f);
				int valueR = FMath::FRandRange(0, 11);
				decal->SetActorRotation(HitResult.Normal.ToOrientationRotator());
				decal->GetDecal()->CreateDynamicMaterialInstance()->SetScalarParameterValue("IMGN", valueR);
				BulletSplat = decal;
			}
		}
		HitDestroy();
	}
	else 
	{
		BulletExpiry += DeltaTime;

		Velocity += FVector(0.f, 0.f, -200.f) * DeltaTime;
	}

	if (BulletExpiry > 3) {
		HitDestroy();
	}
}

void ABulletDecal::HitDestroy()
{
	Destroy();
}

