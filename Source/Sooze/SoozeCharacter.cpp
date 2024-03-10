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
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GliderMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GlidingMesh"));
	GliderMesh->SetupAttachment(RootComponent);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void ASoozeCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	check(GetCharacterMovement());
	//check(MovementComponent);

	//Add Input Mapping Context
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
}

void ASoozeCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	if(IsGliding)
	{ 
		StopGliding(); 
	}
	
}

void ASoozeCharacter::SetGravity(float Scale)
{
	GetCharacterMovement()->GravityScale = Scale;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASoozeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASoozeCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASoozeCharacter::Look);

		//Gliding
		EnhancedInputComponent->BindAction(GlideAction, ETriggerEvent::Started, this, &ASoozeCharacter::Glide);

		//Dive
		EnhancedInputComponent->BindAction(DiveAction, ETriggerEvent::None, this, &ASoozeCharacter::GlideDive);

		//EnhancedInputComponent->BindAction(GlideAction, ETriggerEvent::Started, this, &ASoozeCharacter::TryFlying);


		//Climbing
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
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	bIsDiving = false;

	UE_LOG(LogTemp, Warning, TEXT("Moving"));

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		FVector ForwardDirection;
		FVector RightDirection;

		if (MovementComponent && MovementComponent->IsClimbing())
		{
			ForwardDirection = FVector::CrossProduct(MovementComponent->GetClimbSurfaceNormal(), -GetActorRightVector());
			RightDirection = FVector::CrossProduct(MovementComponent->GetClimbSurfaceNormal(), GetActorUpVector());
		}
		/*else if (bIsFlying)
		{
			UpdateFlyRotation(MovementVector);
		}*/
		else
		{
			// get forward vector
			ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

			// get right vector 
			RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			
		}
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}

}

void ASoozeCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ASoozeCharacter::Glide()
{
	UE_LOG(LogTemp, Warning, TEXT("Glide"));
	if (IsGliding == false)
	{
		StartGliding();
	}
	else
	{
		StopGliding();
	}

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
		GetCharacterMovement()->MaxAcceleration = 1024;
		GetCharacterMovement()->MaxWalkSpeed = 1000;
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
	}
}

void ASoozeCharacter::StopGliding()
{
	ApplyOriginalSettings();
	IsGliding = false;
	GliderMesh->SetVisibility(false);
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
}

void ASoozeCharacter::DescentPlayer()
{
	if (CurrentVelocity.Z != DescendingRate * -1.f && IsGliding == true)
	{
		CurrentVelocity.Z = UKismetMathLibrary::FInterpTo(CurrentVelocity.Z, DescendingRate, Delta, 3.f);
		float Gravity = 1.0f;
		if (GetCharacterMovement()->GravityScale < 0.0f) { Gravity = GetCharacterMovement()->GravityScale; }
		GetCharacterMovement()->Velocity.Z = DescendingRate * -1.f * Gravity;
		UE_LOG(LogTemp, Warning, TEXT("Descent"));
		FollowCamera->SetFieldOfView(FMath::FInterpTo(90.f, 110.f, Delta, 3.0f));


		if (bIsDiving)
		{
			FollowCamera->SetFieldOfView(FMath::FInterpTo(FollowCamera->FieldOfView, 110.f, Delta, 3.0f));

			DescendingRate = DiveDecendingRate;
			if (GetCharacterMovement()->MaxWalkSpeed < DiveMaxSpeed)
			{
				GetCharacterMovement()->MaxWalkSpeed += DiveSpeedIncrease;
				GetCharacterMovement()->MaxAcceleration += DiveAccelerationIncrease;
			}
			
		}
		else
		{
			DescendingRate = 300.f;
			FollowCamera->SetFieldOfView(FMath::FInterpTo(FollowCamera->FieldOfView, 130.f, Delta, 3.0f));

		}
	}
}

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

	 UE_LOG(LogTemp, Warning, TEXT("apply set"));
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
