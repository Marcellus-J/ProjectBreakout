// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTBREAKOUT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();
	UFUNCTION(BlueprintCallable, Category = "Health" )
	void TakeDamage(float DamageAmount);

	UFUNCTION(BlueprintCallable, Category = "Health" )
	void Heal(float HealAmount);

	UFUNCTION(BlueprintPure, Category = "Health" )
	float GetHealth() const { return CurrentHealth; }

	UFUNCTION(BlueprintPure, Category = "Health" )
	float GetMaxHealth() const { return MaxHealth; }


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health" )
	float MaxHealth = 100.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health" )
	float CurrentHealth;

	UFUNCTION(BlueprintImplementableEvent, Category = "Health" )
	void OnHealthChanged(float NewHealth, float DeltaHealth);

	UFUNCTION(BlueprintImplementableEvent, Category = "Health" )
	void OnDeath();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
};
