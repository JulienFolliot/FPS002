// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS002CrystalWeapon.h"
#include "Components/BoxComponent.h"
#include "../FPS002Projectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPS002CrystalWeapon::AFPS002CrystalWeapon()
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	/*MeshFoot = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FootMesh"));
	MeshFoot->SetOnlyOwnerSee(false);
	MeshFoot->SetupAttachment(GetDefaultAttachComponent());
	MeshFoot->bCastDynamicShadow = false;
	MeshFoot->CastShadow = false;*/


	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	MeshBody = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BodyMesh"));
	MeshBody->SetOnlyOwnerSee(false);
	MeshBody->SetupAttachment(GetDefaultAttachComponent());
	MeshBody->bCastDynamicShadow = false;
	MeshBody->CastShadow = false;

	BoxCapsule = CreateDefaultSubobject<UBoxComponent>(FName("BoxCapsule"));
	BoxCapsule->SetupAttachment(MeshBody);

	BoxCapsule->OnComponentHit.AddDynamic(this, &AFPS002CrystalWeapon::OnHit);

	// Default offset from the character location for projectiles to spawn
	MuzzleOffset = FVector(50.0f, 3.5f, 56.0f);



}

void AFPS002CrystalWeapon::Fire()
{

	// Try and fire a projectile
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{

			MuzzleOffset = FVector(65.0f, HorizontalPositions[FMath::RandRange(0, 7)], VerticalPositions[FMath::RandRange(0, 2)]);

			FRotator SpawnRotation = MeshBody->GetRelativeRotation();

			SpawnRotation.Pitch += 10.0f;

			SpawnRotation.Yaw += 10.0f;

			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			FVector SpawnLocation = MeshBody->GetRelativeLocation() + SpawnRotation.RotateVector(MuzzleOffset);

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// Spawn the projectile at the muzzle
			World->SpawnActor<AFPS002Projectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}

	// Try and play the sound if specified
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, MeshBody->GetRelativeLocation());
	}
	/*
	// Try and play a firing animation if specified
	if (FireAnimation != nullptr)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Character->GetMesh1P()->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}*/
}

// Called when the game starts or when spawned
void AFPS002CrystalWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS002CrystalWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator newBodyRotator = MeshBody->GetRelativeRotation();
	float deltaRotation = DeltaTime * maxRotationSpeed;
	newBodyRotator.Yaw += deltaRotation;
	MeshBody->SetRelativeRotation(newBodyRotator);

}

void AFPS002CrystalWeapon::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("WEAPON HIIIIIIT"));

	if (HitComp->IsA(AFPS002Projectile::StaticClass())) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OnHit WEAPON"));
	}

}

