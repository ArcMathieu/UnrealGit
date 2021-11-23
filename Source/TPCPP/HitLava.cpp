// Fill out your copyright notice in the Description page of Project Settings.


#include "HitLava.h"
#include "GameFramework/Character.h"

// Sets default values
AHitLava::AHitLava()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DamageType = UDamageType::StaticClass();
	Damage = 1.0f;
	WaitDmgTime = 1.0f;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);
	
	//StaticMesh->SetSimulatePhysics(true);
	StaticMesh->OnComponentHit.AddDynamic(this, &AHitLava::OnHit);

}

// Called when the game starts or when spawned
void AHitLava::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHitLava::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (WaitDmgTime > 0.f)
	{
		WaitDmgTime--;
	}
}

void AHitLava::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character == nullptr)
		return;

	if (WaitDmgTime <= 0.f)
	{
		TSubclassOf<UDamageType> DmgTypeClass = DamageType ? *DamageType : UDamageType::StaticClass();
		Character->TakeDamage(Damage, FDamageEvent(DmgTypeClass), DamageInstigator, this);
		WaitDmgTime = 120;
		GLog->Log("Hit");
	}

}

