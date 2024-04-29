// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoozeCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Components/CustomCharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Kismet/KismetMathLibrary.h"


DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ASoozeCharacter

ASoozeCharacter::ASoozeCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCustomCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GliderMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GlidingMesh"));
	GliderMesh->SetupAttachment(RootComponent);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;	
	CameraBoom->bUsePawnControlRotation = true; 

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	FollowCamera->bUsePawnControlRotation = false;
}

void ASoozeCharacter::BeginPlay()
{
	Super::BeginPlay();
	check(GetCharacterMovement());
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	GliderMesh->SetVisibility(false);
}

void ASoozeCharacter::Tick(float DeltaSeconds)
{
	Delta = DeltaSeconds;
	DescentPlayer();
	FollowCamera->SetFieldOfView(FMath::FInterpTo(FollowCamera->FieldOfView, DesiredCameraFOV, Delta, 3.0f));
}

void ASoozeCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	if(IsGliding)
	{ 
		StopGliding(); 
	}
}

void ASoozeCharacter::SetGravity(float Gravity)
{
	GetCharacterMovement()->GravityScale = Gravity;
}


void ASoozeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASoozeCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASoozeCharacter::Look);
		EnhancedInputComponent->BindAction(GlideAction, ETriggerEvent::Started, this, &ASoozeCharacter::Glide);
		EnhancedInputComponent->BindAction(DiveAction, ETriggerEvent::None, this, &ASoozeCharacter::GlideDive);
		EnhancedInputComponent->BindAction(ClimbAction, ETriggerEvent::Started, this, &ASoozeCharacter::Climb);
		EnhancedInputComponent->BindAction(CancelClimbAction, ETriggerEvent::Started, this, &ASoozeCharacter::CancelClimb);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ASoozeCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	bIsDiving = false;
	UE_LOG(LogTemp, Warning, TEXT("Moving"));

	if (Controller != nullptr)
	{
		if (MovementVector.X != 0.0f && MovementVector.Y == 0.0f)
		{
			GetCharacterMovement()->MaxWalkSpeed = FMath::FInterpTo(GetCharacterMovement()->MaxWalkSpeed, 
				GlideWalkSpeed, Delta, 3.0f);
			UE_LOG(LogTemp, Warning, TEXT("TURNING"));
		}

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		FVector ForwardDirection;
		FVector RightDirection;

		if (MovementComponent && MovementComponent->IsClimbing())
		{
			ForwardDirection = FVector::CrossProduct(MovementComponent->GetClimbSurfaceNormal(), -GetActorRightVector());
			RightDirection = FVector::CrossProduct(MovementComponent->GetClimbSurfaceNormal(), GetActorUpVector());
		}
		else
		{
			ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		}
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ASoozeCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ASoozeCharacter::Glide()
{
	UE_LOG(LogTemp, Warning, TEXT("Glide"));
	if (IsGliding == false) {StartGliding();}
	else {StopGliding();}
}

void ASoozeCharacter::StartGliding()
{
	UE_LOG(LogTemp, Warning, TEXT("Start Gliding"));
	if (CanStartGliding())
	{
		GliderMesh->SetVisibility(true);
		CurrentVelocity = GetCharacterMovement()->Velocity;
		IsGliding = true;
		RecordOriginalSettings();
		GetCharacterMovement()->RotationRate = FRotator(0.f, 250.f, 0.f);
		//GetCharacterMovement()->GravityScale = 0.0;
		if (InField) { GetCharacterMovement()->GravityScale = -1.0f; }
		GetCharacterMovement()->AirControl = 0.9;
		GetCharacterMovement()->BrakingDecelerationFalling = 350.f;
		GetCharacterMovement()->MaxAcceleration = GlideAcceleration;
		GetCharacterMovement()->MaxWalkSpeed = GlideWalkSpeed;
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
	}
}

void ASoozeCharacter::StopGliding()
{
	ApplyOriginalSettings();
	IsGliding = false;
	GliderMesh->SetVisibility(false);
	DesiredCameraFOV = 90.f;
	UE_LOG(LogTemp, Warning, TEXT("Stop Glide"));
}

bool ASoozeCharacter::CanStartGliding()
{
	FHitResult Hit;
	FVector TraceStart = GetActorLocation();
	FVector TraceEnd = GetActorLocation() + GetActorUpVector()* MinimumHeight * -1.f;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	TEnumAsByte<ECollisionChannel>TraceProperties = ECC_Visibility;
	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, TraceProperties, QueryParams);
	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, Hit.bBlockingHit ? FColor::Blue : FColor::Red);

	if (Hit.bBlockingHit == false && GetCharacterMovement()->IsFalling() == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can Glide"));
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can Not Glide!"));
		return false;
	}
}

void ASoozeCharacter::RecordOriginalSettings()
{
	OriginalOrientRotation = GetCharacterMovement()->bOrientRotationToMovement;
	OriginalGravityScale = GetCharacterMovement()->GravityScale;
	OriginalAirControl = GetCharacterMovement()->AirControl;
	OriginalDecelration = GetCharacterMovement()->BrakingDecelerationFalling;
	OriginalAcceleration = GetCharacterMovement()->MaxAcceleration;
	OriginalWalkingSpeed = GetCharacterMovement()->MaxWalkSpeed;
	OriginalDesiredRotation = GetCharacterMovement()->bUseControllerDesiredRotation;
	UE_LOG(LogTemp, Warning, TEXT("rec set"));
	UE_LOG(LogTemp, Warning, TEXT("Descent"));
	UE_LOG(LogTemp, Warning, TEXT("Glide Speed: %f"), GetCharacterMovement()->MaxWalkSpeed);
	UE_LOG(LogTemp, Warning, TEXT("Glide Speed: %d"), GetCharacterMovement()->Velocity.Size());
}

void ASoozeCharacter::DescentPlayer()
{
	if (CurrentVelocity.Z != DescendingRate * -1.f && IsGliding == true)
	{
		CurrentVelocity.Z = UKismetMathLibrary::FInterpTo(CurrentVelocity.Z, DescendingRate, Delta, 3.f);
		GetCharacterMovement()->Velocity.Z = DescendingRate * -1.f;
		DesiredCameraFOV = 110.f;

		if (bIsDiving)
		{
			DescendingRate = DiveDecendingRate;
			if (GetCharacterMovement()->MaxWalkSpeed < DiveMaxSpeed)
			{
				GetCharacterMovement()->MaxWalkSpeed = FMath::FInterpTo(GetCharacterMovement()->MaxWalkSpeed,
					DiveMaxSpeed, Delta,3.0f);
			}
			DesiredCameraFOV = 70.f;
		}
		else
		{
			DescendingRate = 300.f;
			if (GlideMaxWalkSpeed < GetCharacterMovement()->MaxWalkSpeed || GlideMaxAcceleration < GetCharacterMovement()->MaxAcceleration)
			{
				GetCharacterMovement()->MaxWalkSpeed = FMath::FInterpTo(GetCharacterMovement()->MaxWalkSpeed, 
					GlideMaxWalkSpeed, Delta, 0.7f);
			}
		}
	}
}


//float Gravity = 1.0f;
		//if (GetCharacterMovement()->GravityScale < 0.0f) { Gravity = GetCharacterMovement()->GravityScale; } * 1;//Gravity;

void ASoozeCharacter::GlideDive()
{
	if (IsGliding)
	{
		bIsDiving = true;
		UE_LOG(LogTemp, Warning, TEXT("Dive"));
	}
	else
	{
		bIsDiving = false;
	}
}

void ASoozeCharacter::ApplyOriginalSettings()
{
	 GetCharacterMovement()->bOrientRotationToMovement = OriginalOrientRotation;
	 if(!InField){ GetCharacterMovement()->GravityScale = OriginalGravityScale; }
	 GetCharacterMovement()->AirControl = OriginalAirControl;
	 GetCharacterMovement()->BrakingDecelerationFalling = OriginalDecelration;
	 GetCharacterMovement()->MaxAcceleration = OriginalAcceleration;
	 GetCharacterMovement()->MaxWalkSpeed = OriginalWalkingSpeed;
	 GetCharacterMovement()->bUseControllerDesiredRotation = OriginalDesiredRotation;
	 GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
}

void ASoozeCharacter::Climb()
{
	UE_LOG(LogTemp, Warning, TEXT("Climb"));
	MovementComponent = Cast<UCustomCharacterMovementComponent>(GetCharacterMovement());
	MovementComponent->TryClimbing();
}

void ASoozeCharacter::CancelClimb()
{
	UE_LOG(LogTemp, Warning, TEXT("CancelClimb"));
	MovementComponent = Cast<UCustomCharacterMovementComponent>(GetCharacterMovement());
	MovementComponent->CancelClimbing();
}



//void ASoozeCharacter::SetFlying()
//{
//	MovementComponent = Cast<UCustomCharacterMovementComponent>(GetCharacterMovement());
//
//	if (bWantsToFly != (MovementComponent->MovementMode == EMovementMode::MOVE_Flying))
//	{
//		if (bWantsToFly)
//		{
//			bIsFlying = true;
//			MovementComponent->SetMovementMode(EMovementMode::MOVE_Flying);
//			MovementFlyVelocity = MovementComponent->Velocity;
//			MovementComponent->Velocity = { 0, 0, 0 };
//		}
//		else
//		{
//			bIsFlying = false;
//			MovementComponent->SetMovementMode(EMovementMode::MOVE_Falling);
//			MovementComponent->AddImpulse(MovementFlyVelocity * 1.5f, true);
//		}
//	}
//}
//
//void ASoozeCharacter::UpdateFlyRotation(FVector2D MoveInput)
//{
//	GlideRotCurrent.Roll = FMath::FInterpTo(GlideRotCurrent.Roll, MoveInput.X * GlideRotMaxRoll, Delta, 10);
//
//	GlideRotCurrent.Pitch = FMath::FInterpTo(GlideRotCurrent.Pitch, FMath::Clamp(GlideRotCurrent.Pitch + (MoveInput.Y * GlideRotAccel.Pitch * Delta), 
//		GlideRotMaxPitch * -1.0f, GlideRotMaxPitch), Delta, 100);
//
//	GlideRotCurrent.Yaw = FMath::FInterpTo(GlideRotCurrent.Yaw, GlideRotCurrent.Yaw + (MoveInput.X * GlideRotAccel.Yaw * Delta), 100,Delta);
//
//	SetActorRotation(GlideRotCurrent.Add(0.0, -90.0, 0.0));
//
//	
//
//	MoveFly();
//}
//
//void ASoozeCharacter::UpdateFlySpeed()
//{
//	GlideSpeedCurrent = FMath::Clamp(GlideSpeedCurrent + (GlideSpeedAccel * Delta * ((GlideRotCurrent.Pitch * -1) / 90)), 0.0, GlideGravityMax);
//}
//
//void ASoozeCharacter::MoveFly()
//{
//	MovementFlyVelocity = FMath::Lerp(FVector(MovementFlyVelocity.X, MovementFlyVelocity.Y, FMath::Max(MovementFlyVelocity.Z - (GlideGravityAccel * Delta), GlideGravityMax * -1)), 
//		GlideRotCurrent.Vector() * GlideSpeedCurrent, GlideSpeedCurrent / GlideGravityMax);
//	
//	AddActorWorldOffset(MovementFlyVelocity * Delta, true);
//}
//
//void ASoozeCharacter::TryFlying()
//{
//	if (bIsFlying)
//	{
//		bWantsToFly = false;
//		SetFlying();
//	}
//	else
//	{
//		bWantsToFly = true;
//		SetFlying();
//	}
//}
