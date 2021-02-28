// Fill out your copyright notice in the Description page of Project Settings.

#include "NeonPainterSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "../Stroke.h"
#include "Misc/Guid.h"

UNeonPainterSaveGame* UNeonPainterSaveGame::Create() 
{
	UNeonPainterSaveGame* NewSaveGame = Cast<UNeonPainterSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	NewSaveGame->SlotName = FGuid::NewGuid().ToString();
	return NewSaveGame;
}

bool UNeonPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

UNeonPainterSaveGame* UNeonPainterSaveGame::Load(FString SlotName)
{
	return Cast<UNeonPainterSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
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
