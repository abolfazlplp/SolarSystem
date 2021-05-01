// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework\RotatingMovementComponent.h"
#include "GameFramework\SpringArmComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planet.generated.h"

UCLASS()
class SOLARSYSTEM_API APlanet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlanet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(EditAnywhere)
	float DistanceToParent = 0.f;
	UPROPERTY(EditAnywhere)
	FVector PlanetScale = FVector().OneVector;
	UPROPERTY(EditAnywhere)
	FRotator RotationRate = FRotator(0.f,15.f,0.f);

};
