// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 400.f;

	UPROPERTY(VisibleAnywhere, Category = "Camera Components")
	class USpringArmComponent* SpringArmComp;
	
	UPROPERTY(VisibleAnywhere, Category = "Camera Components")
	class UCameraComponent* CameraComp;

	void Move(float Value);
};
