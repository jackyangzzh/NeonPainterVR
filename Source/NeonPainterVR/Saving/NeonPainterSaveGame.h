// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "NeonPainterSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class NEONPAINTERVR_API UNeonPainterSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	static UNeonPainterSaveGame* Create();

	bool Save();
};
