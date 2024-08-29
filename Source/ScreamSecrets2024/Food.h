// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Food.generated.h"

UENUM(BlueprintType)
enum class EAttribute : uint8
{
	WellMade,
	Healthy,
	Normal,
	Poisoned,
	Nailed,
	Glassed,
	Repulsive,
	Infested
};

UCLASS()
class SCREAMSECRETS2024_API AFood : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	AFood();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Food")
	EAttribute FoodAttribute{};
};
