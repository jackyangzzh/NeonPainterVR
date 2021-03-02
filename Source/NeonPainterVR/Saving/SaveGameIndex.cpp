// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGameIndex.h"
#include "Kismet/GameplayStatics.h"

const FString USaveGameIndex::SlotName = "PaintIndex";

USaveGameIndex* USaveGameIndex::Load ()
{
	USaveGameIndex* Index = Cast<USaveGameIndex>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
	if (!Index)
	{
		Index = Cast<USaveGameIndex>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
		Index->Save();
	}
	return Index;
}

bool USaveGameIndex::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

void USaveGameIndex::AddSaveGame(UNeonPainterSaveGame* SaveGame)
{
	SlotNames.Add(SaveGame->GetSlotName());
}