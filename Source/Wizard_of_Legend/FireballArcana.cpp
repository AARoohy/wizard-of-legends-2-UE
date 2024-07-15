#include "FireballArcana.h"

#include "StatContainer.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"

UFireballArcana::UFireballArcana()
{
    CooldownTime = 2.0f;
    ThirdProjectileDelay = 0.5f;
    CycleResetTime = 1.0f;
    ProjectileCount = 0;
    bIsOnCooldown = false;
}

void UFireballArcana::ActivateAbility_Implementation(AActor* User)
{
    if (bIsOnCooldown)
    {
        UE_LOG(LogTemp, Warning, TEXT("Ability is on cooldown!"));
        return;
    }
    float attackPower=10;

    UStatContainer* StatContainer = User->FindComponentByClass<UStatContainer>();
    UStat* stat=StatContainer->GetStat(EStatsType::AttackPower);
    if(IsValid(stat))
        attackPower=stat->GetValue();
    else
        UE_LOG(LogTemp, Error, TEXT("No attackpower stat found"));


    
    User->GetWorldTimerManager().ClearTimer(ResetCycleTimerHandle);

    //Spawn FireBall
    FVector ShootDirection = User->GetActorForwardVector();
    FVector SpawnLocation = User->GetActorLocation() + User->GetActorForwardVector() * FireBallSpawnDistance;
    FRotator SpawnRotation = User->GetActorRotation();
    AFireballArcanaProjectile* Fireball = User->GetWorld()->SpawnActor<AFireballArcanaProjectile>(FireballClass, SpawnLocation, SpawnRotation);
    
    Fireball->FireInDirection(ShootDirection);
    
    if (ProjectileCount == 2)// Handling fireball 3 
    {
        float superPower= attackPower*3;
        UE_LOG(LogTemp, Log, TEXT("Casting third fireball with damage: %f"), superPower);
        ProjectileCount = 0;
        bIsOnCooldown = true;

        User->GetWorldTimerManager().SetTimer(CooldownTimerHandle, this, &UFireballArcana::EndCooldown, CooldownTime, false);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Casting normal fireball with damage: %f"), attackPower);
        ProjectileCount++;

        if(ProjectileCount<2)// fireball 1 and 2
        {
            User->GetWorldTimerManager().SetTimer(ResetCycleTimerHandle, this, &UFireballArcana::ResetCycle, CycleResetTime, false);
        }
        else// fireball 3 preparation 
        {
            User->GetWorldTimerManager().SetTimer(ResetCycleTimerHandle, this, &UFireballArcana::ResetCycle, ThirdProjectileDelay, false);
        }
    }
}

void UFireballArcana::ResetCycle()
{
    UE_LOG(LogTemp, Log, TEXT("Resetting fireball casting cycle."));
    ProjectileCount = 0;
}

void UFireballArcana::EndCooldown()
{
    UE_LOG(LogTemp, Log, TEXT("Cooldown ended. Ability can be used again."));
    bIsOnCooldown = false;
}
