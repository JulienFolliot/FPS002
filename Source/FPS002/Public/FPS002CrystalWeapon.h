// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "FPS002CrystalWeapon.generated.h"

UCLASS()
class FPS002_API AFPS002CrystalWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPS002CrystalWeapon();

	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCapsule;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* MeshBody;

	/*UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* MeshFoot;*/

	/** Bool for AnimBP to switch to another animation set */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Body)
	float maxRotationSpeed;

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AFPS002Projectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

	float VerticalPositions[3] = { 16.0f, 30.8f, 44.0f }; // { 28.0f, 42.8f, 56.0f };
	float HorizontalPositions[8] = { 39.0f, 28.0f, 17.0f, 6.0f, -6.0f, -17.0f, -28.0f, -39.0f };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
