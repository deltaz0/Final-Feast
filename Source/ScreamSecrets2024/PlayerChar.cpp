// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChar.h"

// Sets default values
APlayerChar::APlayerChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	GameManager = Cast<UGameManager>(GetGameInstance());
	PlayerStats = Cast<APlayerStatManager>(GetPlayerState());

	if (GameManager)
	{
		UE_LOG(LogTemp, Display, TEXT("Game Manager cast successful"));
	}
	else
		UE_LOG(LogTemp, Error, TEXT("Casting failed"));
}

// Called every frame
void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerChar::RestoreHunger(int value)
{
	if (hunger + value > 100)
		hunger = 100;
	else
		hunger += value;
}

void APlayerChar::DepleteHunger(int value)
{
	if (hunger - value < 0)
	{
		DepleteHealth(value - hunger);
		hunger = 0;
	}
	else
		hunger -= value;
}

void APlayerChar::RestoreHealth(int value)
{
	if (health + value > 100)
		health = 100;
	else
		health += value;
}

void APlayerChar::DepleteHealth(int value)
{
	if (health - value < 0)
	{
		health = 0;
		Death();
	}
	else
		health -= value;
}

void APlayerChar::AddItem(AItem* Item)
{

}

void APlayerChar::ClearItems()
{

}

void APlayerChar::Death()
{
	UE_LOG(LogTemp, Display, TEXT("I am dead lol"));
}