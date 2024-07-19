// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class WIZARD_OF_LEGEND_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	bool CanMove;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Player Character")
	FVector DirectionBasedOnCamera(FVector InputDirection, UCameraComponent* CameraComponent);


	UFUNCTION(BlueprintCallable, Category = "Player Character")
	void RotatePlayerToMouseCursor();
	UFUNCTION(BlueprintCallable, Category = "Player Character")
	FRotator GetPlayerRotatorToMouseCursor();

private:
	APlayerController* PlayerController;

};
