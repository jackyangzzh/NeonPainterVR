// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Materials/MaterialInterface.h"

#include "NeonPainterSaveGame.generated.h"

USTRUCT()
struct FStrokeState
{
	GENERATED_BODY()

	UPROPERTY()
		TSubclassOf<class AStroke> Class;

	UPROPERTY()
		FTransform Transform;

	UPROPERTY()
		class UMaterialInterface* Material;

	UPROPERTY()
		TArray<FVector> ControlPoints;

	UPROPERTY()
		TArray<FVector> RandomColors;

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

	static UNeonPainterSaveGame* Load(FString SlotName);

	void SetState(FString NewState) { State = NewState; }
	FString GetState() const { return State; }

	static FString GetImagePath(const FString SlotName);
	FString GetSlotName() const { return SlotName; }

	void SerializeFromWorld(UWorld* World);
	void DeserializeToWorld(UWorld* world);

	void Delete();

private:
	UPROPERTY()
		FString State;

	UPROPERTY()
		FString SlotName;

	UPROPERTY()
		TArray<FStrokeState> StrokeArray;
};
