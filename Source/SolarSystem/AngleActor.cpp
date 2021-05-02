// Fill out your copyright notice in the Description page of Project Settings.


#include "AngleActor.h"

// Sets default values
AAngleActor::AAngleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAngleActor::BeginPlay()
{
	Super::BeginPlay();

	FVector CharacterDirection = Character->GetActorForwardVector();
	UE_LOG(LogTemp, Warning, TEXT("MainDirection is: %s"), *(CharacterDirection.ToString()));

	FVector CharacterToObjectVector = Character->GetActorLocation() - Object->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("CharacterToObjectDirection is: %s"), *(CharacterToObjectVector.ToString()));

	auto CharacterToObjectDirection = CharacterToObjectVector.GetSafeNormal();

	auto CSize = CharacterDirection.Size();
	auto OSize = CharacterToObjectDirection.Size();
	float Angle = FMath::RadiansToDegrees(acosf(FVector::DotProduct(CharacterDirection, CharacterToObjectDirection)/(CSize * OSize)));
	UE_LOG(LogTemp, Warning, TEXT("Angle is: %f"), Angle);

	if (Angle <= 90.f) {
		UE_LOG(LogTemp, Warning, TEXT("Object is in Front!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Object is in Back!"));
	}
		
}

// Called every frame
void AAngleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

