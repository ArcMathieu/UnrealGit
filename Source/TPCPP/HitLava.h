// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitLava.generated.h"

UCLASS()
class TPCPP_API AHitLava : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	class AController* DamageInstigator;
	
public:	
	// Sets default values for this actor's properties
	AHitLava();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle TimerHandle_PainTimer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnyWhere, Category = "Components")
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		float WaitDmgTime;

	bool inContact;
	int direction;
};
