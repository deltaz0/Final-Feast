// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Item.h"
#include "GameManager.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
	Wandering,
	Eating
};

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Items")
	EItemType FItemType{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Items")
	UTexture2D* FIcon{};

	FItemData()
		: FItemType(EItemType::Milk), FIcon(nullptr){}

	FItemData(EItemType itemType, UTexture2D* icon)
	{
		FItemType = itemType;
		FIcon = icon;
	}
};

/**
 * 
 */
UCLASS()
class SCREAMSECRETS2024_API UGameManager : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UGameManager();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Game State")
	EGameState CurrentState = EGameState::Wandering;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Game State")
	int CurrentDay = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game State")
	TMap<int, int> DayRounds;

	UFUNCTION(BlueprintCallable, Category = "Game State")
	void ProgressDay();

	UFUNCTION(BlueprintCallable, Category = "Game State")
	int GetRoundsCount();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player")
	TArray<AItem*> HeldItems{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Items")
	TArray<FItemData> HeldItemData{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player")
	int CurrentHealth{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player")
	int CurrentHunger{};

	UFUNCTION(BlueprintCallable, Category = "Player")
	void RestoreHealth(int value);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void DepleteHealth(int value);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void RestoreHunger(int value);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void DepleteHunger(int value);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void PlayerDeath();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void ClearItems();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddItems(AItem* item);
};
