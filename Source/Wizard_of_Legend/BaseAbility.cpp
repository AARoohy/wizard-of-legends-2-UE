// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAbility.h"

void UBaseAbility::ActivateAbility_Implementation(APlayerCharacter* User)
{
	
}

void UBaseAbility::Tick_Implementation(float deltaTime)
{
	
}

float UBaseAbility::GetCooldownPercent(APlayerCharacter* User)
{
	return CurrentCooldown/CooldownTime;
}

