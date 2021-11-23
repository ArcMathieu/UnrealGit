// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JumpPad.generated.h"

UCLASS()
class TPCPP_API AJumpPad : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere, Category = "Components")
	class UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnyWhere, Category = "Variables")
	int JumpHeight;
	
public:	
	// Sets default values for this actor's properties
	AJumpPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
};
