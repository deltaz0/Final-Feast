// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"

UGameManager::UGameManager()
{
	// Initialize game stats

	CurrentDay = 1;

	DayRounds.Add(1, 5);
	DayRounds.Add(2, 7);
	DayRounds.Add(3, 9);
	DayRounds.Add(4, 10);
	DayRounds.Add(5, 15);

	// Initialize player stats

	CurrentHealth = 100;
	CurrentHunger = 100;
}

void UGameManager::ProgressDay()
{
	CurrentDay++;
}

int UGameManager::GetRoundsCount()
{
	return DayRounds[CurrentDay];
}

void UGameManager::RestoreHealth(int value)
{
	if (CurrentHealth + value > 100)
		CurrentHealth = 100;
	else
		CurrentHealth += value;
}

void UGameManager::DepleteHealth(int value)
{
	if (CurrentHealth - value < 0)
	{
		CurrentHealth = 0;
		PlayerDeath();
	}
	else
		CurrentHealth -= value;
}

void UGameManager::RestoreHunger(int value)
{
	if (CurrentHunger + value > 100)
		CurrentHunger = 100;
	else
		CurrentHunger += value;
}

void UGameManager::DepleteHunger(int value)
{
	if (CurrentHunger - value < 0)
	{
		DepleteHealth(value - CurrentHunger);
	}
	else
		CurrentHunger -= value;
}

void UGameManager::PlayerDeath()
{
	UE_LOG(LogTemp, Display, TEXT("I'm dead asf lol!!!"));
}

void UGameManager::ClearItems()
{
	HeldItems.Empty();
}

void UGameManager::AddItems(AItem* item)
{
	if (HeldItemData.Num() < 5)
	{
		UE_LOG(LogTemp, Display, TEXT("Added item %s"), *item->GetName());

		FItemData ItemData(item->ItemType, item->Icon);
		HeldItemData.Add(ItemData);
	}
	else
		return;
}