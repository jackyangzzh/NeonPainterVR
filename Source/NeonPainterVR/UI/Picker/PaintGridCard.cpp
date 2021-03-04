// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintGridCard.h"

void UPaintGridCard::SetPaintingName(FString PaintingName)
{
	SlotName->SetText(FText::FromString(PaintingName));
}
