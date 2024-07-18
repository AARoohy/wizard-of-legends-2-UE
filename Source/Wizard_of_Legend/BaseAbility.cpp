// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAbility.h"


void ABaseAbility::ActivateAbility()
{
	if(CurrentCooldown>0)
	{
		OnCooldownWarning.Broadcast();
		return;
	}
	OnActivateAbility();
}


void ABaseAbility::Setup(APlayerCharacter* User)
{
	this->CurrentUser=User;
	StatContainer = User->FindComponentByClass<UStatContainer>();
	OnSetup(User);
}

void ABaseAbility::OnSetup_Implementation(APlayerCharacter* user)
{
	
}


void ABaseAbility::OnActivateAbility_Implementation()
{
	
}

void ABaseAbility::Tick_Implementation(float deltaTime)
{
	if(CurrentCooldown>0)
	{
		CurrentCooldown-=deltaTime;
		if(CurrentCooldown<=0)
			EndCooldown();
	}
}

float ABaseAbility::GetCooldownPercent()
{
	return CurrentCooldown/CooldownTime;
}

void ABaseAbility::StartCooldown()
{
	CurrentCooldown=CooldownTime;
	OnCooldownStart.Broadcast(CooldownTime);
}

void ABaseAbility::EndCooldown()
{
	CurrentCooldown=0;
	OnAbilityReady.Broadcast();
}

bool ABaseAbility::GetIsOnCooldown()
{
	return CurrentCooldown>0;
}


