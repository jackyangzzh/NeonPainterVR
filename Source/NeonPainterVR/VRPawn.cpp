// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"
#include "Engine/World.h"
#include "PaintHandController.h"
#include "Saving/NeonPainterSaveGame.h"
#include "PaintMode.h"
#include "UI/Picker/Picker.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AVRPawn::AVRPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);
}

void AVRPawn::BeginPlay()
{
	Super::BeginPlay();

	if (PaintHandControllerClass)
	{
		RightPaintHandController = GetWorld()->SpawnActor<AHandControllerBase>(PaintHandControllerClass);
		RightPaintHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightPaintHandController->SetHand(EControllerHand::Right);
		RightPaintHandController->SetOwner(this);
	}

	if (MenuHandControllerClass)
	{
		LeftMenuHandController = GetWorld()->SpawnActor<AHandControllerBase>(MenuHandControllerClass);
		LeftMenuHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		LeftMenuHandController->SetHand(EControllerHand::Left);
		LeftMenuHandController->SetOwner(this);
	}
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Released, this, &AVRPawn::RightTriggerReleased);

	PlayerInputComponent->BindAxis(TEXT("PageRight"), this, &AVRPawn::PageRightInput);
}

void AVRPawn::PageRightInput(float value)
{
	int32 PageOffset = 0;
	PageOffset += value > PageThreshold ? 1 : 0;
	PageOffset -= value < -PageThreshold ? 1 : 0;

	if(PageOffset != PreviousPageOffset && PageOffset != 0)
	{
		UpdatePage(PageOffset);
	}

	PreviousPageOffset = PageOffset;
}

void AVRPawn::UpdatePage(int32 Offset)
{
	for (TActorIterator<APicker> PickerItr(GetWorld()); PickerItr; ++PickerItr)
	{
		PickerItr->UpdatePage(Offset);
	}
}
