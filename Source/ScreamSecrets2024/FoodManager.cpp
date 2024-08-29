// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodManager.h"

// Sets default values
AFoodManager::AFoodManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFoodManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFoodManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodManager::IncrementRound()
{
	CurrentRound++;
}

