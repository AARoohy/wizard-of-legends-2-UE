#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Stat.h"
#include "StatContainer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WIZARD_OF_LEGEND_API UStatContainer : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStatContainer();

	UPROPERTY(EditAnywhere, Category = "Stat Container")
	TArray<TSubclassOf<UStat>> StatClasses;

	
	UFUNCTION(BlueprintCallable, Category = "Stat Container")
	void AddStat(UStat* Stat);

	UFUNCTION(BlueprintCallable, Category = "Stat Container")
	void AddModifier(FStatModifier Modifier);

	UFUNCTION(BlueprintCallable, Category = "Stat Container")
	UStat* GetStat(EStatsType StatType);

protected:
	virtual void BeginPlay() override;
	TMap<EStatsType, UStat*> Stats;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
