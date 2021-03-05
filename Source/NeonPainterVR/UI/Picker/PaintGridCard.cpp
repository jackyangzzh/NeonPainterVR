// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintGridCard.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

void UPaintGridCard::SetPaintingName(FString Name)
{
	PaintName = Name;
	SlotName->SetText(FText::FromString(PaintName));

	SlotButton->OnClicked.AddDynamic(this, &UPaintGridCard::OnClickButton);
}

void UPaintGridCard::OnClickButton()
{
	UStereoLayerFunctionLibrary::ShowSplashScreen();
	UGameplayStatics::OpenLevel(GetWorld(),TEXT("Canvas"), true, "SlotName=" + PaintName);
}
