// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 400.f;

	//UPROPERTY(VisibleInstanceOnly)
	//int32 VisibleInstanceOnlyInt = 12;

	//UPROPERTY(VisibleDefaultsOnly)
	//int32 VisibleDefaultsOnlyInt = 5;

	//UPROPERTY(EditDefaultsOnly)
	//int32 EditDefaultsOnlyInt = 9;

	//UPROPERTY(EditInstanceOnly)
	//int32 EditInstanceOnlyInt = 3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "My Variables", meta = (AllowPrivateAccess = "true"))
	//int32 VisibleAnywhereInt = 22;

	//UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "My Variables", meta = (AllowPrivateAccess = "true"))
	//int32 EditAnywhereInt = 11;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
