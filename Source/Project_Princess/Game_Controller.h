// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Project_PrincessGameMode.h"
#include "Engine/UserDefinedStruct.h"
#include "MenuPawn.h"
#include "Project_PrincessCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Game_Controller.generated.h"

UCLASS()
class PROJECT_PRINCESS_API AGame_Controller : public AActor
{
	GENERATED_BODY()

	

public:	
	// Sets default values for this actor's properties
	AGame_Controller();

	UFUNCTION()
		void TraceForInteraction();

	UFUNCTION()
		void UpdateFocalDistance();

	UFUNCTION()
		void SetPlayerCameraSettings();
	
	//Create and store the ActiveComponent
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USceneComponent* ActiveComponent;

	//Create and store the character mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USkeletalMeshComponent* PlayerCharacterMesh;

	//Store the bool to determine if the menu is open
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool MenuOpen;

	//Store the bool to determine if the journal is open
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool JournalOpen;

	//Store the bool to determine if the inventory is open
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool InventoryOpen;

	//Store the bool to determine if the player is inspecting an item
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsInspecting;

	//Store a reference to a journal instance
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUserWidget* UIJournalInstance;

	//Store a reference to the inventory object instance
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUserWidget* UIInventoryInstance;

	//Store a reference to a focused object using a line trace by channel
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* FocusedObject;

	//Look into this
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHoldTrace;

	//Look into this as well
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSearchForKey;

	//Likely used to check last door used/opened
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* ActiveDoor;

	//Is game loading
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Loading;

	//Is saving game
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Saving;

	//Store a reference to the current game save instance
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USaveGame* SaveGameInstance;

	//Store an array of items that were collected or triggered
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> CollectedOrTriggered;

	//Store an array of clues found
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> FoundClues;

	//Store a reference to Game Menu instance
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUserWidget* GameMenuInstance;

	//Bool for flashlight on or off
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bFlashlightOn;

	//Store an array of loaded streamed levels
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> LoadedStreamedLevels;

	//Store an array of unloaded streamed levels
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> UnloadedStreamedLevels;

	//Store a Data table reference for Settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStruct* FMyAdvancedSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AMenuPawn* myMenuPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		APawn* myGamePawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bGamepadInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float FocalDistance;

	//The following variables are for inventory use only
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<FName> CollectedJournalTitles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<FName> CollectedJournalHeadlines;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<FName> CollectedJournalContent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<int> KeyIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<UStruct*> Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<UStruct*> InventoryClueData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		bool bHasFlashlight;

	/*The following series of functions save various variables to the save game state*/

	UFUNCTION()
		void SaveGame();

	UFUNCTION()
		void SaveInventoryAndPlayer();

	UFUNCTION()
		void SaveCurrentLevel();

	UFUNCTION()
		void SaveCollectedItems();

	UFUNCTION()
		void SaveFoundClues();

	UFUNCTION()
		void SaveFlashlight();

	UFUNCTION()
		void FinishSaving();

	UFUNCTION()
		void PrepareSaveGame();

	//This function handles all the door saves
	UFUNCTION()
		void SaveDoorStates();

	UFUNCTION()
		void RemoveDoorsFromUnlock();

	UFUNCTION()
		void SaveUnlockedDoors();

	UFUNCTION()
		void SaveDoorRotations();

	UFUNCTION()
		void PreLoad();

	UFUNCTION()
		void DisplayHUDText();

	/* The following series of functions are used when loading levels and assets */
	UFUNCTION()
		void LoadGame();

	UFUNCTION()
		void LoadFoundClues();

	UFUNCTION()
		void LoadInventory();

	UFUNCTION()
		void LoadPlayerTransform();

	UFUNCTION()
		void RemoveTakenActors();

	UFUNCTION()
		void LoadFlashlight();

	UFUNCTION()
		void LoadDoorStates();

	UFUNCTION()
		void Load();

	UFUNCTION()
		void UnlockDoors();

	UFUNCTION()
		void SetDoorRotations();

	UFUNCTION()
		void EndLoading();
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
