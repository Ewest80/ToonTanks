// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Find distance to the tank
	if (Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		// Check to see if tank is in range

		// If in range, rotate turret towards tank
		if (Distance <= FireRange)
		{
			RotateTurret(Tank->GetActorLocation());
		}
	}
}


void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
