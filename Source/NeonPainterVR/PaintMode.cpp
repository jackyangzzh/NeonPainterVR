// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintMode.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Saving/NeonPainterSaveGame.h"

void APaintMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	SlotName = UGameplayStatics::ParseOption(Options, "SlotName");

	UE_LOG(LogTemp, Warning, TEXT("SlotName: %s"), *SlotName);
}

void APaintMode::BeginPlay()
{
	Super::BeginPlay();

	UNeonPainterSaveGame* LoadFile = UNeonPainterSaveGame::Load(SlotName);
	if (LoadFile)
	{
		LoadFile->DeserializeToWorld(GetWorld());
		UStereoLayerFunctionLibrary::HideSplashScreen();
	}
}
