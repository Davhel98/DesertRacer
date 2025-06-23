// Fill out your copyright notice in the Description page of Project Settings.


#include "DesertRacerGameMode.h"

#include "Kismet/GameplayStatics.h"

void ADesertRacerGameMode::ResetLevel(bool IsWin)
{
	float ResetTime = IsWin ? WinResetTime : LoseResetTime;

	GetWorldTimerManager().SetTimer(ResetGameTimer, this, &ADesertRacerGameMode::OnResetGameTimerTimeout, 1.0f, false, ResetTime);
}

void ADesertRacerGameMode::OnResetGameTimerTimeout()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainLevel"));
}
