// Fill out your copyright notice in the Description page of Project Settings.
#include "PaintHandController.h"
#include "Engine/World.h"


// Sets default values
APaintHandController::APaintHandController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APaintHandController::BeginPlay()
{
	Super::BeginPlay();

}

void APaintHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentStroke)
	{
		CurrentStroke->Update(GetActorLocation());
	}

}

void APaintHandController::TriggerPressed()
{
	CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeClass);
	CurrentStroke->SetActorLocation(GetActorLocation());
}

void APaintHandController::TriggerReleased()
{
	CurrentStroke = nullptr;
}

