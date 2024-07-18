#include "FireballArcana.h"

#include "StatContainer.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"

UFireballArcana::UFireballArcana()
{
	ProjectileCount = 0;
	IsOnCooldown=false;
}
void UFireballArcana::Tick_Implementation(float deltaTime)
{
	if(CurrentCooldown>0)
	{
		CurrentCooldown-=deltaTime;
		if(CurrentCooldown<=0)
			EndCooldown();
		return;
	}
	if(currentResetTimer>0)
	{
		currentResetTimer-=deltaTime;
		if(currentResetTimer<=0)
			ResetCycle();
	}
}


void UFireballArcana::ActivateAbility_Implementation(APlayerCharacter* User)
{
	if (IsOnCooldown)
	{
		return;
	}
	float attackPower = 10;

	UStatContainer* StatContainer = User->FindComponentByClass<UStatContainer>();
	UStat* stat = StatContainer->GetStat(EStatsType::AttackPower);
	if (IsValid(stat))
		attackPower = stat->GetValue();
	else
		UE_LOG(LogTemp, Error, TEXT("No attackpower stat found"));


	User->GetWorldTimerManager().ClearTimer(ResetCycleTimerHandle);

	if (ProjectileCount == 2) // Handling fireball 3 
	{
		attackPower *= ThirdProjectileDamageMulti;
		ProjectileCount = 0;
		IsOnCooldown = true;

		
		currentResetTimer=0;
		CurrentCooldown=CooldownTime;
		OnCooldownStart.Broadcast(CooldownTime);
	}
	else
	{
		ProjectileCount++;
		if (ProjectileCount < 2) // fireball 1 and 2
			currentResetTimer=CycleResetTime;
		else // fireball 3 preparation 
			currentResetTimer=ThirdProjectileDelay;
	}

	//Spawn FireBall
	FVector ShootDirection = User->GetActorForwardVector();
	FVector SpawnLocation = User->GetActorLocation() + User->GetActorForwardVector() * FireBallSpawnDistance;
	FRotator SpawnRotation = User->GetActorRotation();
	AFireballArcanaProjectile* Fireball = User->GetWorld()->SpawnActor<AFireballArcanaProjectile>(
		FireballClass, SpawnLocation, SpawnRotation);
	Fireball->Speed = FireBallSpeed;
	Fireball->Shooter = User;
	Fireball->Damage = attackPower;
	Fireball->Direction = ShootDirection;
}

void UFireballArcana::ResetCycle()
{
	//UE_LOG(LogTemp, Log, TEXT("Resetting fireball casting cycle."));
	ProjectileCount = 0;
}

void UFireballArcana::EndCooldown()
{
	IsOnCooldown = false;
	
	OnAbilityReady.Broadcast();
}
