// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Project_PrincessHUD.generated.h"

UCLASS()
class AProject_PrincessHUD : public AHUD
{
	GENERATED_BODY()

public:
	AProject_PrincessHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	//Create the Widgets
	class UClass* HUDWidgetClass;
	class UUserWidget* fpsWidget;

	virtual void BeginPlay() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

