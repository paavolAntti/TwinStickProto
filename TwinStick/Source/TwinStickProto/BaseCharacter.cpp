// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

void ABaseCharacter::CalculateDead()
{
	if (health <= 0) 
	{
		isDead = true;
	}
	else 
	{
		isDead = false;
	}
}

void ABaseCharacter::CalculateHealth(float delta)
{
	health += delta;
	CalculateDead();
}

#if WITH_EDITOR
void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	isDead = false;
	health = 100;
	Super::PostEditChangeProperty(PropertyChangedEvent);
	CalculateDead();
}
#endif

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

