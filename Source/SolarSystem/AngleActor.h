// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AngleActor.generated.h"

UCLASS()
class SOLARSYSTEM_API AAngleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAngleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UPROPERTY(EditAnywhere)
		AActor* Character = nullptr;
	UPROPERTY(EditAnywhere)
		AActor* Object = nullptr;

};
