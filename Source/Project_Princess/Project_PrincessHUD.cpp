// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Project_PrincessHUD.h"
#include "Engine.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UserWidget.h"
#include "UObject/ConstructorHelpers.h"

AProject_PrincessHUD::AProject_PrincessHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;

	static ConstructorHelpers::FClassFinder<UUserWidget> HUDWidgetObj
	(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonHUD"));

	if (HUDWidgetObj.Succeeded())
	{
		HUDWidgetClass = HUDWidgetObj.Class;
		UE_LOG(LogTemp, Warning, TEXT("HUD Class found"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("HUD Class not found!"));
		//HudWidgetObj not found
		HUDWidgetClass = nullptr;
	}
}


void AProject_PrincessHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
}

void AProject_PrincessHUD::BeginPlay()
{
	Super::BeginPlay();

	//HUDWidgetClass exists
	if (HUDWidgetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Begin Drawing HUD"));
		fpsWidget = CreateWidget<UUserWidget>(this->GetOwningPlayerController(),
			this->HUDWidgetClass);
		fpsWidget->AddToViewport();
	}
}
