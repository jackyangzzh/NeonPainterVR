// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintGrid.h"
#include "Components/SizeBox.h"

void UPaintGrid::AddPainting()
{
	if (!PaintGrid) return;
	
	UUserWidget* newWidget = CreateWidget<UUserWidget>(GetWorld(), GridClass);

	if (!newWidget) return;

	USizeBox* CardContainer = Cast<USizeBox>(PaintGrid->GetChildAt(0));

	if (!CardContainer) return;

	CardContainer->AddChild(newWidget);

}