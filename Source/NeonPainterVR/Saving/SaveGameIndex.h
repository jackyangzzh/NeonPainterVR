// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "NeonPainterSaveGame.h"
#include "SaveGameIndex.generated.h"

/**
 * 
 */
UCLASS()
class NEONPAINTERVR_API USaveGameIndex : public USaveGame
{
	GENERATED_BODY()
	
public: 
	static USaveGameIndex* Load();
	bool Save();

	void AddSaveGame(UNeonPainterSaveGame* SaveGame);
	TArray<FString> GetSlotNames() const { return SlotNames; }

private:
	static const FString SlotName;

	UPROPERTY()
		TArray<FString> SlotNames;
};
