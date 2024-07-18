
#include "AbilityDatabase.h"
#include "BaseAbility.h"


ABaseAbility* UAbilityDatabase::GetAbilityByID(int32 ID) const
{
	for (TSubclassOf<ABaseAbility> Ability : Abilities)
	{
		ABaseAbility* a=Ability.GetDefaultObject();
		if (Ability && a->AbilityID == ID)
		{
			return a;
		}
	}
	UE_LOG(LogTemp,Error,TEXT("No Ability found with ID %i"),ID);
	return nullptr;
}

ABaseAbility* UAbilityDatabase::GetAbilityInstanceByID(int32 ID, UObject* Outer) const
{
	ABaseAbility* Ability = GetAbilityByID(ID);
	if (Ability)
	{
		return DuplicateObject<ABaseAbility>(Ability, Outer);
	}
	return nullptr;
}
