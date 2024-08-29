// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Item.h"
#include "PlayerStatManager.generated.h"

UENUM(BlueprintType)
enum class EPlayerCondition : uint8
{
	Normal,
	Poisoned,
	Infested
};

/**
 * 
 */
UCLASS()
class SCREAMSECRETS2024_API APlayerStatManager : public APlayerState
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player")
	TArray<AItem*> HeldItems{};

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
