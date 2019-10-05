// Fill out your copyright notice in the Description page of Project Settings.


#include "Game_Controller.h"
#include "UObject/ConstructorHelpers.h"

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



}

// Called when the game starts or when spawned
void AGame_Controller::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		//Get the current game mode
		AProject_PrincessGameMode* MyGameMode = (AProject_PrincessGameMode *)GetWorld()->GetAuthGameMode();
		
		//Grab the currently controlled pawn class
		myGamePawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		//Grab the mesh from the character player
		if (GetWorld()->ContainsActor(myGamePawn))
		{
			UE_LOG(LogTemp, Warning, TEXT("Game Pawn Found"));

			//Find the skeletalmeshcomponent that is attached to the player character
			PlayerCharacterMesh = myGamePawn->FindComponentByClass<USkeletalMeshComponent>();
			
			//Test to see if the mesh was found
			if (PlayerCharacterMesh)
			{
				UE_LOG(LogTemp, Warning, TEXT("The name of the skeletal mesh found was: %s"), *myGamePawn->GetName());
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("The name of the skeletal mesh found was not found!"));
			}
		}
		
		if(FMyAdvancedSettings)
		
		//Testing some stuff
		UE_LOG(LogTemp, Warning, TEXT("Game Mode found. Good Job!"));
		UE_LOG(LogTemp, Warning, TEXT("Name of the object is %s"), *myGamePawn->GetName());
	}
	else
	{
		//Testing some stuff
		UE_LOG(LogTemp, Warning, TEXT("Game Mode not found. Try again."));
		UE_LOG(LogTemp, Warning, TEXT("Failed to get name or grab pawn class"));
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
