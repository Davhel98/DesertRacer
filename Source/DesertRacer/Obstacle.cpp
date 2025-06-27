// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	SetRootComponent(CapsuleComp);

	ObstacleSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ObstacleSprite"));
	ObstacleSprite->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	CapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::OverlapBegin);

	// Get the game mode and cast it to our custom game mode
	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
	DesertRacerGameMode = Cast<ADesertRacerGameMode>(GameMode);
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacle::OverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);

	if (IsValid(Player))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "Obstacle OverlapBegin");
		if (Player->CanMove)
		{
			Player->CanMove = false;

			UGameplayStatics::PlaySound2D(GetWorld(), HitSound);

			if (IsValid(DesertRacerGameMode))
			{
				DesertRacerGameMode->ResetLevel(IsFinishLine);
			}
		}
	}
}

