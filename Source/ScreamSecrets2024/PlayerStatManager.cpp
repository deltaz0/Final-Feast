// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatManager.h"

void APlayerStatManager::RestoreHealth(int value)
{
	if (CurrentHealth + value > 100)
		CurrentHealth = 100;
	else
		CurrentHealth += value;
}

void APlayerStatManager::DepleteHealth(int value)
{
	if (CurrentHealth - value < 0)
	{
		CurrentHealth = 0;
		PlayerDeath();
	}
	else
		CurrentHealth -= value;
}

void APlayerStatManager::RestoreHunger(int value)
{
	if (CurrentHunger + value > 100)
		CurrentHunger += 100;
	else
		CurrentHunger += value;
}

void APlayerStatManager::DepleteHunger(int value)
{
	if (CurrentHunger - value < 0)
	{
		DepleteHealth(value - CurrentHunger);
	}
	else
		CurrentHunger -= value;
}

void APlayerStatManager::PlayerDeath()
{
	UE_LOG(LogTemp, Display, TEXT("I'm dead asf lol!!!"));
}

void APlayerStatManager::ClearItems()
{
	HeldItems.Empty();
}

void APlayerStatManager::AddItems(AItem* item)
{
	if (HeldItems.Num() < 5)
		HeldItems.Add(item);
	else
		return;
}
