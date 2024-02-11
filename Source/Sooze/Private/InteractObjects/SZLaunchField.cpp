// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractObjects/SZLaunchField.h"
#include "Sooze/SoozeCharacter.h"

// Sets default values
ASZLaunchField::ASZLaunchField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Field = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Field"));
	Field->OnComponentBeginOverlap.AddDynamic(this, &ASZLaunchField::OnOverlapBegin);
	Field->OnComponentEndOverlap.AddDynamic(this, &ASZLaunchField::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ASZLaunchField::BeginPlay()
{
	Super::BeginPlay();
}

void ASZLaunchField::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const auto Character = Cast<ASoozeCharacter>(OtherActor);
	if(Character->GetIsGliding())
	{ 
		Character->SetGravity(-1.0f);
		Character->SetInField(true);
	}
	
}

void ASZLaunchField::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const auto Character = Cast<ASoozeCharacter>(OtherActor);
	
	Character->SetInField(false);
}

// Called every frame
void ASZLaunchField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

