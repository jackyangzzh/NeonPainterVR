// Fill out your copyright notice in the Description page of Project Settings.

#include "NeonPainterSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "../Stroke.h"
#include "Misc/Guid.h"
#include "SaveGameIndex.h"

UNeonPainterSaveGame* UNeonPainterSaveGame::Create() 
{
	UNeonPainterSaveGame* NewSaveGame = Cast<UNeonPainterSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	NewSaveGame->SlotName = FGuid::NewGuid().ToString();

	if(!NewSaveGame->Save()) return nullptr;

	USaveGameIndex* Index = USaveGameIndex::Load();
	Index->AddSaveGame(NewSaveGame);
	Index->Save();

	return NewSaveGame;
}

bool UNeonPainterSaveGame::Save()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Saved"));
	for (FString Name : USaveGameIndex::Load()->GetSlotNames())
	{
		UE_LOG(LogTemp, Warning, TEXT("Name of File is %s"), *Name);
	}

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
