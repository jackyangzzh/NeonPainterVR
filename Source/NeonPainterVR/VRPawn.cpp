// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPawn.h"
#include "Engine/World.h"
#include "PaintHandController.h"
#include "Saving/NeonPainterSaveGame.h"

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

	UNeonPainterSaveGame* Painting = UNeonPainterSaveGame::Create();
	if (Painting && Painting->Save())
	{
		CurrentSlotName = Painting->GetSlotName();
	}
	if (PaintHandControllerClass)
	{
		RightPaintHandController = GetWorld()->SpawnActor<AHandControllerBase>(PaintHandControllerClass);
		RightPaintHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightPaintHandController->SetOwner(this);
	}
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Released, this, &AVRPawn::RightTriggerReleased);

	PlayerInputComponent->BindAction(TEXT("Save"), EInputEvent::IE_Released, this, &AVRPawn::Save);
	PlayerInputComponent->BindAction(TEXT("Load"), EInputEvent::IE_Released, this, &AVRPawn::Load);
}

void AVRPawn::Save()
{
	UNeonPainterSaveGame* SaveFile = UNeonPainterSaveGame::Load(CurrentSlotName);
	if (SaveFile)
	{
		SaveFile->SetState("Hello There");
		SaveFile->SerializeFromWorld(GetWorld());
		SaveFile->Save();
	}

}

void AVRPawn::Load()
{
	UNeonPainterSaveGame* LoadFile = UNeonPainterSaveGame::Load(CurrentSlotName);
	if (LoadFile)
	{
		LoadFile->DeserializeToWorld(GetWorld());
	}
}


