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
		CurrentStroke->Update(GetActorLocation(), CurrentColor);
	}

}

void APaintHandController::TriggerPressed()
{
	CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeClass);
	CurrentStroke->SetActorLocation(GetActorLocation());
	//CurrentStroke->SetColor(CurrentColor);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *CurrentColor.ToString());
}

void APaintHandController::TriggerReleased()
{
	CurrentStroke = nullptr;
}

