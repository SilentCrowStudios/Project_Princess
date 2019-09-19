// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MasterInteractableObject.generated.h"

UCLASS()
class PROJECT_PRINCESS_API AMasterInteractableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMasterInteractableObject();

	//Hold a static mesh object for master object
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* AMasterObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
		void Interaction();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
