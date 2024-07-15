
#include "AbilityDatabase.h"
#include "BaseAbility.h"


UBaseAbility* UAbilityDatabase::GetAbilityByID(int32 ID) const
{
	for (UBaseAbility* Ability : Abilities)
	{
		if (Ability && Ability->AbilityID == ID)
		{
			return Ability;
		}
	}
	UE_LOG(LogTemp,Error,TEXT("No Ability found with ID %i"),ID);
	return nullptr;
}

UBaseAbility* UAbilityDatabase::GetAbilityInstanceByID(int32 ID, UObject* Outer) const
{
	UBaseAbility* Ability = GetAbilityByID(ID);
	if (Ability)
	{
		return DuplicateObject<UBaseAbility>(Ability, Outer);
	}
	return nullptr;
}
