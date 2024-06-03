// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractObjects/SZLaunchField.h"
#include "Sooze/SoozeCharacter.h"

ASZLaunchField::ASZLaunchField()
{
	PrimaryActorTick.bCanEverTick = true;

	Field = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Field"));
	Field->OnComponentBeginOverlap.AddDynamic(this, &ASZLaunchField::OnOverlapBegin);
	Field->OnComponentEndOverlap.AddDynamic(this, &ASZLaunchField::OnOverlapEnd);
}

void ASZLaunchField::BeginPlay()
{
	Super::BeginPlay();
}

void ASZLaunchField::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const auto Character = Cast<ASoozeCharacter>(OtherActor);
	if(Character->GetIsGliding())
	{ 
		Character->SetInField(true);
	}
}

void ASZLaunchField::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const auto Character = Cast<ASoozeCharacter>(OtherActor);
	Character->SetInField(false);
}

void ASZLaunchField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

