// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentHealth = MaxHealth;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeDamage(float DamageAmount)
{
	if (DamageAmount <= 0 || CurrentHealth == 0) return;

	float OldHealth = CurrentHealth;
	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.0f, MaxHealth);
	float DeltaHealth = CurrentHealth - OldHealth;

	OnHealthChanged(CurrentHealth, DeltaHealth);

	if (CurrentHealth <= 0) 
	{
		OnDeath();
	}
}

void UHealthComponent::Heal(float HealAmount)
{
	if (HealAmount <= 0 || CurrentHealth >= MaxHealth) return;

	float OldHealth = CurrentHealth;
	CurrentHealth = FMath::Clamp(CurrentHealth + HealAmount, 0.0f, MaxHealth);
	float DeltaHealth = CurrentHealth - OldHealth;

	OnHealthChanged(CurrentHealth, DeltaHealth);

}
