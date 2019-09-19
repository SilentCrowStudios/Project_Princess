// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Game_Controller.generated.h"

UCLASS()
class PROJECT_PRINCESS_API AGame_Controller : public AActor
{
	GENERATED_BODY()

	

public:	
	// Sets default values for this actor's properties
	AGame_Controller();

	//Create and store the ActiveComponent
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USceneComponent* ActiveComponent;

	//Create and store the character mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USkeletalMeshComponent* PlayerCharacterMesh;
	//Store the bool to determine if the menu is open
		bool MenuOpen;

	//Store the bool to determine if the journal is open
		bool JournalOpen;

	//Store the bool to determine if the inventory is open
		bool InventoryOpen;

	//Store the bool to determine if the player is inspecting an item
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
		bool bHoldTrace;

	//Look into this as well
		bool bSearchForKey;

	//Likely used to check last door used/opened
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* ActiveDoor;

	//Is game loading
		bool Loading;

	//Is saving game
		bool Saving;

	//Store a reference to the current game save instance
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USaveGame* SaveGameInstance;

	//Store an array of items that were collected or triggered
		TArray<FString>* CollectedOrTriggered;

	//Store an array of clues found
		TArray<AActor>* FoundClues;

	//Store a reference to Game Menu instance
		UUserWidget* GameMenuInstance;

	//Bool for flashlight on or off
		bool bFlashlightOn;

	//Store an array of loaded streamed levels
		TArray<FName> LoadedStreamedLevels;

	//Store an array of unloaded streamed levels
		TArray<FName> UnloadedStreamedLevels;


		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
