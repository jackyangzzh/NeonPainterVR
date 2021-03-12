// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PaintMode.generated.h"

/**
 * 
 */
UCLASS()
class NEONPAINTERVR_API APaintMode : public AGameModeBase
{
	GENERATED_BODY()

public: 
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	void Save();
	void Load();

	UFUNCTION(BlueprintCallable)
		void SaveAndExit();

protected:
	void BeginPlay() override;

private:
	UPROPERTY()
	FString SlotName;
};
