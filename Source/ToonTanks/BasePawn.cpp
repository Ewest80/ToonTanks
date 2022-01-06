// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraShakeBase.h"
#include "Projectile.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}


void ABasePawn::HandleDestruction()
{
	// TODO: Visual / Sound effects
	if (DeathParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, GetActorLocation(), GetActorRotation());
	}
	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	}
	if (DeathCameraShakeClass)
	{
		GetWorld()->GetFirstPlayerController()->ClientPlayCameraShake(DeathCameraShakeClass);
	}
}


void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();

	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	FRotator CurrentRotation = TurretMesh->GetComponentRotation();
	FRotator InterRotation = FMath::RInterpTo(CurrentRotation, LookAtRotation, GetWorld()->GetDeltaSeconds(), 5.f);

	TurretMesh->SetWorldRotation(InterRotation);
}


void ABasePawn::Fire()
{
	FVector Location = ProjectileSpawnPoint->GetComponentLocation();
	FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	Projectile->SetOwner(this);
}
