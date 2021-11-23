// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletDecal.generated.h"

UCLASS()
class TPCPP_API ABulletDecal : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABulletDecal();

	USceneComponent* RootComp;

	UPROPERTY(EditAnyWhere, Category = "Components")
		class UStaticMeshComponent* BulletMesh;

	UPROPERTY(EditAnyWhere, Category = "Components")
		class UProjectileMovementComponent* BulletMovement;

	UPROPERTY(EditAnyWhere, Category = "Components")
		class UMaterialInterface* BulletSplatTxt;

	class ADecalActor* BulletSplat;

	UPROPERTY(EditAnyWhere)
		FVector Velocity = FVector(100.f);

private:

	float BulletExpiry;
	bool canSpawnDecal;

	FTimerHandle TimerHandle_Die;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void HitDestroy();

	float TimeAlpha;

};