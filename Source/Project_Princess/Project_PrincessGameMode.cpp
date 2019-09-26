// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Project_PrincessGameMode.h"
#include "Project_PrincessHUD.h"
#include "Project_PrincessCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_PrincessGameMode::AProject_PrincessGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Project_Princess/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = AProject_PrincessCharacter::StaticClass();

	// use our custom HUD class
	HUDClass = AProject_PrincessHUD::StaticClass();
}
