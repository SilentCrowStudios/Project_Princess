// Fill out your copyright notice in the Description page of Project Settings.


#include "Game_Controller.h"

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
	
}

// Called every frame
void AGame_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

