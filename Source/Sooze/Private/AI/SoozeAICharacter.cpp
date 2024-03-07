// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SoozeAICharacter.h"

// Sets default values
ASoozeAICharacter::ASoozeAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASoozeAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASoozeAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASoozeAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

