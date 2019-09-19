// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UserWidget.h"
#include "Game_Controller.generated.h"

UCLASS()
class PROJECT_PRINCESS_API AGame_Controller : public AActor
{
	GENERATED_BODY()

	//Create and store the Default Scene Root
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USceneComponent* DefaultSceneRoot;

	//Create and store the ActiveComponent
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USceneComponent* ActiveComponent;

	//Create and store the character mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		USkeletalMeshComponent* PlayerCharacterMesh;

public:	
	// Sets default values for this actor's properties
	AGame_Controller();

private:

	//Store the bool to determine if the menu is open
	bool MenuOpen;

	//Store the bool to determine if the journal is open
	bool JournalOpen;

	//Store the bool to determine if the inventory is open
	bool InventoryOpen;

	//Store the bool to determine if the player is inspecting an item
	bool IsInspecting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUserWidget* UIJournalInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUserWidget* UIInventoryInstance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
