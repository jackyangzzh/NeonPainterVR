// Fill out your copyright notice in the Description page of Project Settings.

#include "NeonPainterSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "../Stroke.h"

UNeonPainterSaveGame* UNeonPainterSaveGame::Create() 
{
	USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
	return Cast<UNeonPainterSaveGame>(NewSaveGame);
}

bool UNeonPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, TEXT("Test"), 0);
}

UNeonPainterSaveGame* UNeonPainterSaveGame::Load()
{
	return Cast<UNeonPainterSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Test"), 0));
}

void UNeonPainterSaveGame::SerializeFromWorld(UWorld* World)
{
	StrokeArray.Empty();
	for (TActorIterator<AStroke> stroke(World); stroke; ++stroke)
	{
		StrokeArray.Add(stroke->SerializeToStruct());
	}
}

void UNeonPainterSaveGame::DeserializeToWorld(UWorld* World)
{
	for (TActorIterator<AStroke> stroke(World); stroke; ++stroke)
	{
		stroke->Destroy();
	}

	for (FStrokeState StrokeState: StrokeArray)
	{
		AStroke::DeserializeFromStruct(World, StrokeState);
	}
}
