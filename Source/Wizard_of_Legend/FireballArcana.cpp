#include "FireballArcana.h"

#include "StatContainer.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"

AFireballArcana::AFireballArcana()
{
	ProjectileCount = 0;
}
void AFireballArcana::Tick_Implementation(float deltaTime)
{
	Super::Tick_Implementation(deltaTime);
	if(currentResetTimer>0)
	{
		currentResetTimer-=deltaTime;
		if(currentResetTimer<=0)
			ResetCycle();
	}
}


void AFireballArcana::OnActivateAbility_Implementation()
{
	if (GetIsOnCooldown())
	{
		return;
	}
	float attackPower = 10;

	UStat* stat = StatContainer->GetStat(EStatsType::AttackPower);
	if (IsValid(stat))
		attackPower = stat->GetValue();
	else
		UE_LOG(LogTemp, Error, TEXT("No attackpower stat found"));


	CurrentUser->GetWorldTimerManager().ClearTimer(ResetCycleTimerHandle);

	if (ProjectileCount == 2) // Handling fireball 3 
	{
		attackPower *= ThirdProjectileDamageMulti;
		ProjectileCount = 0;
		
		currentResetTimer=0;
		StartCooldown();
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
	FVector ShootDirection = CurrentUser->GetActorForwardVector();
	FVector SpawnLocation = CurrentUser->GetActorLocation() + CurrentUser->GetActorForwardVector() * FireBallSpawnDistance;
	FRotator SpawnRotation = CurrentUser->GetActorRotation();
	AProjectile* Fireball = CurrentUser->GetWorld()->SpawnActor<AProjectile>(
		FireballClass, SpawnLocation, SpawnRotation);
	Fireball->Speed = FireBallSpeed;
	Fireball->Shooter = CurrentUser;
	Fireball->Damage = attackPower;
	Fireball->Direction = ShootDirection;
}

void AFireballArcana::ResetCycle()
{
	//UE_LOG(LogTemp, Log, TEXT("Resetting fireball casting cycle."));
	ProjectileCount = 0;
}

void AFireballArcana::EndCooldown()
{
	OnAbilityReady.Broadcast();
}
