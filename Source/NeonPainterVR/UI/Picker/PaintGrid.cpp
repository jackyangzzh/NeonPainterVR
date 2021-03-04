// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintGrid.h"
#include "Components/SizeBox.h"

void UPaintGrid::AddPainting(int32 index, FString PaintName)
{
	if (!PaintGrid) return;
	
	UPaintGridCard* newWidget = CreateWidget<UPaintGridCard>(GetWorld(), GridClass);

	newWidget->SetPaintingName(PaintName);

	if (!newWidget) return;

	USizeBox* CardContainer = Cast<USizeBox>(PaintGrid->GetChildAt(index));

	if (!CardContainer) return;

	CardContainer->AddChild(newWidget);

}