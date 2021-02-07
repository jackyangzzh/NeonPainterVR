// Fill out your copyright notice in the Description page of Project Settings.

#include "NeonPainterSaveGame.h"
#include "Kismet/GameplayStatics.h"


UNeonPainterSaveGame* UNeonPainterSaveGame::Create() 
{
	USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
	return Cast<UNeonPainterSaveGame>(NewSaveGame);
}

bool UNeonPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, TEXT("Test"), 0);
}
