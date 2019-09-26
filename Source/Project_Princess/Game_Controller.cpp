// Fill out your copyright notice in the Description page of Project Settings.


#include "Game_Controller.h"

void AGame_Controller::TraceForInteraction()
{
}

void AGame_Controller::UpdateFocalDistance()
{
}

void AGame_Controller::SetPlayerCameraSettings()
{
}

// Sets default values
AGame_Controller::AGame_Controller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	//if (MyGameMode)	//Successfully grabbed game mode
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Game Mode found. Good Job!"));
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Game Mode not found. Try again."));
	//}

}

// Called when the game starts or when spawned
void AGame_Controller::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetWorld())
	{
		AProject_PrincessGameMode* MyGameMode = (AProject_PrincessGameMode *)GetWorld()->GetAuthGameMode();

		UE_LOG(LogTemp, Warning, TEXT("Game Mode found. Good Job!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Mode not found. Try again."));
	}
}

// Called every frame
void AGame_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGame_Controller::SaveGame()
{
}

void AGame_Controller::SaveInventoryAndPlayer()
{
}

void AGame_Controller::SaveCurrentLevel()
{
}

void AGame_Controller::SaveCollectedItems()
{
}

void AGame_Controller::SaveFoundClues()
{
}

void AGame_Controller::SaveFlashlight()
{
}

void AGame_Controller::FinishSaving()
{
}

void AGame_Controller::PrepareSaveGame()
{
}

void AGame_Controller::SaveDoorStates()
{
}

void AGame_Controller::RemoveDoorsFromUnlock()
{
}

void AGame_Controller::SaveUnlockedDoors()
{
}

void AGame_Controller::SaveDoorRotations()
{
}

void AGame_Controller::PreLoad()
{
}

void AGame_Controller::DisplayHUDText()
{
}

void AGame_Controller::LoadGame()
{
}

void AGame_Controller::LoadFoundClues()
{
}

void AGame_Controller::LoadInventory()
{
}

void AGame_Controller::LoadPlayerTransform()
{
}

void AGame_Controller::RemoveTakenActors()
{
}

void AGame_Controller::LoadFlashlight()
{
}

void AGame_Controller::LoadDoorStates()
{
}

void AGame_Controller::Load()
{
}

void AGame_Controller::UnlockDoors()
{
}

void AGame_Controller::SetDoorRotations()
{
}

void AGame_Controller::EndLoading()
{
}
