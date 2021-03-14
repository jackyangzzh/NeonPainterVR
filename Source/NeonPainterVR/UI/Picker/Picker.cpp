// Fill out your copyright notice in the Description page of Project Settings.


#include "Picker.h"
#include "PaintGrid.h"
#include "ActionBar.h"
#include "../../Saving/SaveGameIndex.h"
#include "../../Saving/NeonPainterSaveGame.h"

// Sets default values
APicker::APicker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root); 

	PaintGrid = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaintGrid"));
	PaintGrid->SetupAttachment(GetRootComponent());

	ActionBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("ActionBar"));
	ActionBar->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APicker::BeginPlay()
{
	Super::BeginPlay();

	UActionBar *ActionBarWidget = Cast<UActionBar>(ActionBar->GetUserWidgetObject());
	if (ActionBarWidget) 
	{
		ActionBarWidget->SetParentPicker(this);
	}

	LoadSlots();
	LoadDots();
}

void APicker::AddPaint()
{
	UNeonPainterSaveGame::Create();

	LoadSlots();
	LoadDots();
}

void APicker::DeletePaint()
{
	UPaintGrid *PaintGridWidget = Cast<UPaintGrid>(PaintGrid->GetUserWidgetObject());

	if (!PaintGridWidget)
		return;

	PaintGridWidget->ClearPaint();
}

void APicker::LoadSlots()
{
	UPaintGrid *PaintGridWidget = Cast<UPaintGrid>(PaintGrid->GetUserWidgetObject());
	if (!PaintGridWidget)
		return;

	PaintGridWidget->ClearPaint();

	int32 index = 0;

	for (FString SlotName : USaveGameIndex::Load()->GetSlotNames())
	{
		PaintGridWidget->AddPainting(index, SlotName);
		index++;
	}
}

void APicker::LoadDots()
{
	UPaintGrid *PaintGridWidget = Cast<UPaintGrid>(PaintGrid->GetUserWidgetObject());
	if (!PaintGridWidget) return;

	PaintGridWidget->ClearDots();

	for(int32 i = 0; i < GetPageNumber(); i++)
	{
		PaintGridWidget->AddPageDot(CurrentPageIndex == i);
	}
}

// Called every frame
void APicker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 APicker::GetPageNumber() const
{
	UPaintGrid *PaintGridWidget = Cast<UPaintGrid>(PaintGrid->GetUserWidgetObject());
	if(!PaintGridWidget) return 0;
	 
	int32 SlotLength = USaveGameIndex::Load()->GetSlotNames().Num();
	int32 SlotAverage = PaintGridWidget->GetSlotNumber();

	return FMath::CeilToInt((float) SlotLength / SlotAverage);
}

