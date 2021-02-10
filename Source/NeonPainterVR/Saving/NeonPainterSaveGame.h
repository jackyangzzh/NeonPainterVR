// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "NeonPainterSaveGame.generated.h"

USTRUCT()
struct FStrokeState
{
	GENERATED_BODY()

	UPROPERTY()
		TArray<TSubclassOf<class AStroke>> StrokeArray;

	UPROPERTY()
		TArray<FVector> ControlPoints;
};
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

	static UNeonPainterSaveGame* Load();

	void SetState(FString NewState) { State = NewState; }
	FString GetState() const { return State;  }

	void SerializeFromWorld(UWorld* World);
	void DeserializeToWorld(UWorld* world);

private:
	UPROPERTY()
		FString State;

	UPROPERTY()
		TArray<FStrokeState> StrokeArray;
};
