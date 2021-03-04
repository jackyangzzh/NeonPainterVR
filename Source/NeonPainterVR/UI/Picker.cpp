// Fill out your copyright notice in the Description page of Project Settings.


#include "Picker.h"
#include "../Saving/SaveGameIndex.h"
#include "Picker/PaintGrid.h"

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

	UPaintGrid* PaintGridWidget = Cast<UPaintGrid>(PaintGrid->GetUserWidgetObject());
	if (!PaintGrid) return;

	int32 index = 0;

	for (FString SlotName : USaveGameIndex::Load()->GetSlotNames())
	{
		PaintGridWidget->AddPainting(index, SlotName);
		index++;
	}
}

// Called every frame
void APicker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

