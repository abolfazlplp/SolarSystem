// Fill out your copyright notice in the Description page of Project Settings.


#include "Planet.h"

// Sets default values
APlanet::APlanet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlanet::BeginPlay()
{
	Super::BeginPlay();

	auto SpringArm = FindComponentByClass<USpringArmComponent>();

	if (SpringArm != nullptr)
		SpringArm->TargetArmLength = DistanceToParent;

	auto Sphere = FindComponentByClass<UStaticMeshComponent>();
	if (Sphere != nullptr)
		Sphere->SetWorldScale3D(PlanetScale);

	auto RotatingMovement = FindComponentByClass<URotatingMovementComponent>();
	if (RotatingMovement != nullptr)
		RotatingMovement->RotationRate = RotationRate;


//	if (Moons.Num() == 0)return;
	
}

// Called every frame
void APlanet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

