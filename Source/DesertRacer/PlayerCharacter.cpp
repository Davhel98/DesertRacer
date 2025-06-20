// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	SetRootComponent(CapsuleComp);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	CarSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("CarSprite"));
	CarSprite->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(Controller);

	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (SubSystem)
		{
			SubSystem->AddMappingContext(InputMappingContext, 0);
		}
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
	}
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MoveActionValue = Value.Get<FVector2D>();

	if (CanMove)
	{
		// Handle movement along the Y-axis (forward/backward)
		if (abs(MoveActionValue.Y) > 0.0f)
		{
			float DeltaTime = GetWorld()->DeltaRealTimeSeconds;

			// Handle rotation based on the X-axis input
			if (abs(MoveActionValue.X) > 0.0f)
			{
				float RotationAmount = RotationSpeed * MoveActionValue.X * DeltaTime;
				AddActorWorldRotation(FRotator(-RotationAmount, 0.0f, 0.0f));
			}

			float FinalMovementSpeed = MovementSpeed;

			// If moving backward, reduce speed
			if (MoveActionValue.Y < 0.0f)
			{
				FinalMovementSpeed *= 0.5f;
			}
			
			FVector CurrentLocation = GetActorLocation();
			FVector DistanceToMove = GetActorUpVector() * FinalMovementSpeed * MoveActionValue.Y * DeltaTime;
			FVector NewLocation = CurrentLocation + DistanceToMove;
			
			SetActorLocation(NewLocation);
		}
	}
	else
	{
		// Optionally handle the case where movement is not allowed
		UE_LOG(LogTemp, Warning, TEXT("Movement is currently disabled."));
	}
}

