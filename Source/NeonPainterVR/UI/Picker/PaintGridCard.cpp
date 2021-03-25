// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintGridCard.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "../../Saving/NeonPainterSaveGame.h"

void UPaintGridCard::SetPaintingName(FString Name)
{
	PaintName = Name;
	//SlotName->SetText(FText::FromString(PaintName));

	FString ImagePath = UNeonPainterSaveGame::GetImagePath(Name);
	if (IFileManager::Get().FileExists(*ImagePath))
	{
		FSlateDynamicImageBrush Brush(*ImagePath, FVector2D(1000, 1000), FLinearColor::White);
		Thumbnail->SetBrush(Brush);
	}

	SlotButton->OnClicked.AddDynamic(this, &UPaintGridCard::OnClickButton);
}

void UPaintGridCard::OnClickButton()
{
	UStereoLayerFunctionLibrary::ShowSplashScreen();
	UGameplayStatics::OpenLevel(GetWorld(),TEXT("Canvas"), true, "SlotName=" + PaintName);
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
}

