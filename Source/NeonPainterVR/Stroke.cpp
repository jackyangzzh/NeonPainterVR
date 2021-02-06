// Fill out your copyright notice in the Description page of Project Settings.


#include "Stroke.h"
#include "Components/SplineMeshComponent.h"

// Sets default values
AStroke::AStroke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	StrokeMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("StrokeMesh"));
	StrokeMesh->SetupAttachment(Root);
}

void AStroke::Update(FVector CursorLocation)
{
	FTransform NewStrokeTransform;

	FVector LocalCursorLocation = GetTransform().InverseTransformPosition(CursorLocation);

	NewStrokeTransform.SetLocation(LocalCursorLocation);

	StrokeMesh->AddInstance(NewStrokeTransform);

	UE_LOG(LogTemp, Warning, TEXT("In update function"));

	PreviousCursor = CursorLocation;
}

