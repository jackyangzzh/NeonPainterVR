// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintMode.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Saving/NeonPainterSaveGame.h"

void APaintMode::InitGame(const FString &MapName, const FString &Options, FString &ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	SlotName = UGameplayStatics::ParseOption(Options, "SlotName");

}

void APaintMode::BeginPlay()
{
	Super::BeginPlay();

	Load();

	UStereoLayerFunctionLibrary::HideSplashScreen();
}

void APaintMode::Load()
{
	UNeonPainterSaveGame *LoadFile = UNeonPainterSaveGame::Load(SlotName);
	if (LoadFile)
	{
		LoadFile->DeserializeToWorld(GetWorld());
	}
}

void APaintMode::Save()
{
	UNeonPainterSaveGame *SaveFile = UNeonPainterSaveGame::Load(SlotName);

	if (SaveFile)
	{
		
		SaveFile->SerializeFromWorld(GetWorld());
		SaveFile->Save();
	}
}

void APaintMode::SaveAndExit()
{
	Save();

	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenu"));
}
