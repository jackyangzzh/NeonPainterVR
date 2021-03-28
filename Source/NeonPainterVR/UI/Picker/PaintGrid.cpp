// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintGrid.h"
#include "Components/SizeBox.h"
#include "Components/HorizontalBoxSlot.h"

void UPaintGrid::AddPainting(int32 index, FString PaintName)
{
	if (!PaintGrid) return;

	UPaintGridCard* newWidget = CreateWidget<UPaintGridCard>(GetWorld(), GridClass);

	newWidget->SetPaintingName(PaintName);

	if (!newWidget) return;

	USizeBox* CardContainer = Cast<USizeBox>(PaintGrid->GetChildAt(index));

	if (!CardContainer) return;

	newWidget->SetParentPicker(ParentPicker);
	CardContainer->AddChild(newWidget);

}

void UPaintGrid::ClearPaint()
{
	for (int32 i = 0; i < PaintGrid->GetChildrenCount(); i++)
	{
		USizeBox* CardContainer = Cast<USizeBox>(PaintGrid->GetChildAt(i));
		if (!CardContainer) continue;

		CardContainer->ClearChildren();
	}
}

void UPaintGrid::ClearDots()
{
	if (!PageDots) return;

	PageDots->ClearChildren();
}

void UPaintGrid::SetParentPicker(APicker* newPicker)
{
	ParentPicker = newPicker;
}

void UPaintGrid::AddPageDot(bool active)
{
	if (!PageDots) return;

	auto Dot = CreateWidget<UPageDot>(GetWorld(), PageDotClass);
	if (!Dot) return;

	Dot->SetActive(active);

	UHorizontalBoxSlot* PageDotSlot = PageDots->AddChildToHorizontalBox(Dot);
	PageDotSlot->SetPadding(FMargin(PageDotPadding, 0));
}

int32 UPaintGrid::GetSlotNumber() const
{
	return PaintGrid->GetChildrenCount();
}