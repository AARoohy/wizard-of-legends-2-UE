#include "Stat.h"
#include "FStatModifier.h"

UStat::UStat()
{
}

UStat::UStat(EStatsType InStatType)
	: StatType(InStatType)
{
}

void UStat::AddModifier(const FStatModifier& NewModifier)
{
	Modifiers.Add(NewModifier);
	SetValue(RecalculateValue());
}

float UStat::RecalculateValue()
{
	float BaseValue = 0;
	float TotalDirect = 0;
	float Multiplier = 1.0f;

	for (const FStatModifier& Modifier : Modifiers)
	{
		switch (Modifier.Type)
		{
		case EModifierType::Base:
			BaseValue = Modifier.Value;
			break;
		case EModifierType::Direct:
			TotalDirect += Modifier.Value;
			break;
		case EModifierType::Percentage:
			Multiplier += Modifier.Value / 100.0f;
			break;
		}
	}

	return (BaseValue + TotalDirect) * Multiplier;
}

void UStat::SetValue(float value)
{
	float oldValue = Value;
	Value = value;
	if (oldValue != Value)
		OnValueChanged.Broadcast(oldValue, Value);
}
