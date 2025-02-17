#include "HealthStat.h"
#include "EStatsType.h"

UHealthStat::UHealthStat()
	: UStat(EStatsType::Health), isDead(false)
{
}

float UHealthStat::RecalculateValue()
{
	float HealthPercentage = (Value == 0 && currentHealth == 0) ? 1.0f : currentHealth / Value;

	float NewValue = Super::RecalculateValue();
	SetValue(NewValue);
	SetCurrentHealth(Value * HealthPercentage);

	return NewValue;
}

void UHealthStat::IncreaseCurrentHealth(float amount)
{
	SetCurrentHealth(currentHealth + amount);
}

void UHealthStat::DecreaseCurrentHealth(float amount)
{
	SetCurrentHealth(currentHealth - amount);
}

void UHealthStat::SetCurrentHealth(float amount)
{
	float oldValue = currentHealth;
	currentHealth = FMath::Clamp(amount, 0.0f, Value);
	CheckDeath();
	OnCurrentHealthChanged.Broadcast(oldValue, currentHealth);
}

void UHealthStat::CheckDeath()
{
	if (isDead)
		return;

	if (currentHealth > 0)
		return;

	isDead = true;
	OnDied.Broadcast();
}
