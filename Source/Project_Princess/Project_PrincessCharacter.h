// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UserWidget.h"
#include "Project_PrincessCharacter.generated.h"

class UInputComponent;

UCLASS(config=Game)
class AProject_PrincessCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	class USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* FP_MuzzleLocation;

	/** Gun mesh: VR view (attached to the VR controller directly, no arm, just the actual gun) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* VR_Gun;

	/** Location on VR gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* VR_MuzzleLocation;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	/** Motion controller (right hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* R_MotionController;

	/** Motion controller (left hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* L_MotionController;

	
public:
	AProject_PrincessCharacter();

protected:
	virtual void BeginPlay();
	virtual void Tick(float DeltaSeconds) override;

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class AProject_PrincessProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;

	/** Whether to use motion controller location for aiming. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	uint32 bUsingMotionControllers : 1;

	//Hold the current life of the battery in the flashlight
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character HUD")
		float CurrentBattery;
	//Hold the current life force of the player
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character HUD")
		float Health;
	//Hold the max amount of life a battery can give a flashlight
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character HUD")
		float MaxBatteryLife;
	//Hold the max amount of life force for player
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character HUD")
		float MaxHealth;
	//Hold the amount of batteries player has in inventory
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character HUD")
		int NumOfBatteries;
	//Used to determine input received to turn flashlight on
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character HUD")
		bool FlashlightOn;
	//Used to set the FPS HUD reference, might need to be set in blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Character HUD")
		UUserWidget* FPS_HUD_Ref;
	//Used to display the current and max ammo health (one weapon first, then use as template)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon HUD")
		int currentAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon HUD")
		int maxAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon HUD")
		int totalAmmoInInventory;
	//Used to display and handle the current and max stamina for sprinting and other activities
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character HUD")
		float currentStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character HUD")
		float maxStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character HUD")
		float staminaRechargeRate;

protected:
	
	/** Fires a projectile. */
	void OnFire();

	/** Resets HMD orientation and position in VR. */
	void OnResetVR();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/** Allows the player to toggle the flashlight **/
	void UseFlashlight();

	/** Performs a checksum on the lifespan on the battery to ensure valid usage **/
	bool CheckBattery();

	/** Allows the player to reload the battery, if there is one available **/
	void ReloadBattery();

	/** Use this method for multiple interactable methods **/
	void Interact();

	/** Use this method to reload the ammo for equipped weapon **/
	void ReloadAmmo();

	/** Use this method to return a valid number of ammo left to reload **/
	bool CheckAmmo();

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	struct TouchData
	{
		TouchData() { bIsPressed = false;Location=FVector::ZeroVector;}
		bool bIsPressed;
		ETouchIndex::Type FingerIndex;
		FVector Location;
		bool bMoved;
	};
	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);
	TouchData	TouchItem;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	/* 
	 * Configures input for touchscreen devices if there is a valid touch interface for doing so 
	 *
	 * @param	InputComponent	The input component pointer to bind controls to
	 * @returns true if touch controls were enabled.
	 */
	bool EnableTouchscreenMovement(UInputComponent* InputComponent);

public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};

