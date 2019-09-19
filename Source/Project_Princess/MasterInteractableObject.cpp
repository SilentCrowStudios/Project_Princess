// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterInteractableObject.h"

// Sets default values
AMasterInteractableObject::AMasterInteractableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Attach the master object to the Default Root
	AMasterObject = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Object"));
	RootComponent = AMasterObject;

}

// Called when the game starts or when spawned
void AMasterInteractableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterInteractableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

