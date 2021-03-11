// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"
#include "Engine/World.h"
#include "PaintHandController.h"
#include "Saving/NeonPainterSaveGame.h"
#include "PaintMode.h"
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

	PlayerInputComponent->BindAction(TEXT("Save"), EInputEvent::IE_Released, this, &AVRPawn::Save);
}

void AVRPawn::Save()
{
	auto Mode = Cast<APaintMode>(GetWorld()->GetAuthGameMode());

	if (!Mode)
		return;

	Mode->Save();

	UGameplayStatics::OpenLevel(GetWorld(),TEXT("MainMenu"));
}
