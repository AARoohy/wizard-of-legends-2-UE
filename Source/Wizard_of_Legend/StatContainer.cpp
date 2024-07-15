#include "StatContainer.h"

UStatContainer::UStatContainer()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UStatContainer::BeginPlay()
{
	Super::BeginPlay();
	for (TSubclassOf<UStat> StatClass : StatClasses)
		if (StatClass)
		{
			UStat* NewStat = NewObject<UStat>(this, StatClass);
			if (NewStat)
				AddStat(NewStat);
		}
}


void UStatContainer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStatContainer::AddStat(UStat* Stat)
{
	if (Stat)
	{
		Stats.Add(Stat->GetStatType(), Stat);
	}
}

void UStatContainer::AddModifier(FStatModifier Modifier)
{
	if (UStat** Stat = Stats.Find(Modifier.StatType))
	{
		(*Stat)->AddModifier(Modifier);
	}
}

UStat* UStatContainer::GetStat(EStatsType StatType)
{
	UStat** FoundStat = Stats.Find(StatType);
	if (!FoundStat)
	{
		UE_LOG(LogTemp, Error, TEXT("No Ability found with ID %i"), StatType);
		return nullptr;
	}
	return *FoundStat;
}
