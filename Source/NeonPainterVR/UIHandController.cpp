// Fill out your copyright notice in the Description page of Project Settings.


#include "UIHandController.h"
#include "InputCoreTypes.h"

AUIHandController::AUIHandController()
{
	Pointer = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("Pointer"));
	Pointer->SetupAttachment(GetRootComponent());
}

void AUIHandController::TriggerPressed()
{
	Pointer->PressPointerKey(EKeys::LeftMouseButton);
}

void AUIHandController::TriggerReleased()
{
	Pointer->ReleasePointerKey(EKeys::LeftMouseButton);
}