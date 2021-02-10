// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPawn.h"
#include "Engine/World.h"
#include "HandController.h"
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

	if (HandControllerClass)
	{
		RightHandController = GetWorld()->SpawnActor<AHandController>(HandControllerClass);
		RightHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightHandController->SetOwner(this);
	}
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Released, this, &AVRPawn::RightTriggerReleased);

	PlayerInputComponent->BindAction(TEXT("Save"), EInputEvent::IE_Pressed, this, &AVRPawn::Save);
	PlayerInputComponent->BindAction(TEXT("Load"), EInputEvent::IE_Pressed, this, &AVRPawn::Load);
}

void AVRPawn::Save()
{
	UNeonPainterSaveGame* SaveFile = UNeonPainterSaveGame::Create();
	SaveFile->SetState("Hello There");
	SaveFile->SerializeFromWorld(GetWorld());
	SaveFile->Save();
}

void AVRPawn::Load()
{
	UNeonPainterSaveGame* LoadFile = UNeonPainterSaveGame::Load();
	if (LoadFile)
	{
		LoadFile->DeserializeToWorld(GetWorld());
		UE_LOG(LogTemp, Warning, TEXT("Load State %s"), *LoadFile->GetState());
	}

}


