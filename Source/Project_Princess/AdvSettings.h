/** C++ User defined structs will not appear in Content Browser, but will stil be present in the 
    background and will act like a class. Therefore, there cannot be a blueprint for this asset
**/
#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "AdvSettings.generated.h"

USTRUCT(BlueprintType)
struct FAdvSettings 
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Values")
		float InteractionDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Values")
		bool bTraceOnMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Values")
		float InventoryItemScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Values")
		bool bDepthOfFieldEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Values")
		float CameraApertureDoF;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Values")
		float FocalRegionDoF;
};
