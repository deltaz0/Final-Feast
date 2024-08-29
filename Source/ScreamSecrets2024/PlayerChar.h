// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Food.h"
#include "Item.h"
#include "GameManager.h"
#include "PlayerStatManager.h"
#include "PlayerChar.generated.h"

UCLASS()
class SCREAMSECRETS2024_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Death();

public:	

	TArray<AItem> HeldItems{};

	APlayerChar();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player")
	APlayerStatManager* PlayerStats{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Management")
	UGameManager* GameManager{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player")
	int health{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player")
	int hunger{};

	UFUNCTION(BlueprintCallable, Category = "Player")
	void RestoreHunger(int value);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void DepleteHunger(int value);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void RestoreHealth(int value);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void DepleteHealth(int value);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddItem(AItem* Item);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void ClearItems();
};