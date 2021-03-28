// Fill out your copyright notice in the Description page of Project Settings.

#include "NeonPainterSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "../Stroke.h"
#include "Misc/Guid.h"
#include "../UI/Camera/SnapshotCamera.h"
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
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

UNeonPainterSaveGame* UNeonPainterSaveGame::Load(FString SlotName)
{
	return Cast<UNeonPainterSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
}


void UNeonPainterSaveGame::Delete()
{
	auto Selected = USaveGameIndex::Load();
	Selected->RemovePaint(SlotName);
	Selected->Save();

	UGameplayStatics::DeleteGameInSlot(SlotName, 0);
	IFileManager::Get().Delete(*GetImagePath(SlotName));
}

void UNeonPainterSaveGame::SerializeFromWorld(UWorld* World)
{
	StrokeArray.Empty();
	for (TActorIterator<AStroke> stroke(World); stroke; ++stroke)
	{
		StrokeArray.Add(stroke->SerializeToStruct());
	}

	for (TActorIterator<ASnapshotCamera> SnapshotCamera(World); SnapshotCamera; ++SnapshotCamera)
	{
		FString ThumbnailDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Thumbnail"));
		IFileManager::Get().MakeDirectory(*ThumbnailDir, true);
		FString FileName = SlotName + ".png";

		SnapshotCamera->Screenshot(ThumbnailDir, FileName);
		break;
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


FString UNeonPainterSaveGame::GetImagePath(const FString SlotName)
{
	FString ThumbnailDirectory = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Thumbnail"));
	FString FileName = SlotName + ".png";

	return FPaths::Combine(ThumbnailDirectory, FileName);
}
