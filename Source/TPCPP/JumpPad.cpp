// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpPad.h"
#include "GameFramework/Character.h"

// Sets default values
AJumpPad::AJumpPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);

	StaticMesh->OnComponentHit.AddDynamic(this, &AJumpPad::OnHit);
}

// Called when the game starts or when spawned
void AJumpPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJumpPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJumpPad::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GLog->Log("HitJump");

	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character == nullptr)
		return;

	Character->LaunchCharacter(FVector(0, 0, JumpHeight), false, true);


}

