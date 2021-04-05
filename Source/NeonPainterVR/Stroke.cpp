// Fill out your copyright notice in the Description page of Project Settings.


#include "Stroke.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/World.h"

// Sets default values
AStroke::AStroke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	StrokeMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("StrokeMesh"));
	StrokeMesh->SetupAttachment(Root);

	JointMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("JointMesh"));
	JointMesh->SetupAttachment(Root);
}

void AStroke::Update(FVector CursorLocation)
{
	ControlPoints.Add(CursorLocation);

	if (PreviousCursor.IsNearlyZero()) {
		PreviousCursor = CursorLocation;
		JointMesh->AddInstance(GetNextJointTransform(CursorLocation));
		return;
	}

	StrokeMesh->AddInstance(GetNextSegmentTransform(CursorLocation));
	JointMesh->AddInstance(GetNextJointTransform(CursorLocation));

	PreviousCursor = CursorLocation;
}

FStrokeState AStroke::SerializeToStruct() const
{
	FStrokeState StrokeState;
	StrokeState.Class = GetClass();
	StrokeState.ControlPoints = ControlPoints;
	return StrokeState;
}

AStroke* AStroke::DeserializeFromStruct(UWorld* World, const FStrokeState& StrokeState)
{
	AStroke* Stroke = World->SpawnActor<AStroke>(StrokeState.Class);
	for (FVector ControlPoint : StrokeState.ControlPoints)
	{
		Stroke->Update(ControlPoint);
	}
	return Stroke;
}

void AStroke::RandomChangeMaterial()
{
	UMaterialInterface* material = StrokeMesh->GetMaterial(0);
	

}

FTransform AStroke::GetNextJointTransform(FVector CurrentLocation) const
{
	FTransform JointTransform;

	JointTransform.SetLocation(GetTransform().InverseTransformPosition(CurrentLocation));

	return JointTransform;
}

FTransform AStroke::GetNextSegmentTransform(FVector CurrentLocation) const
{
	FTransform SegmentTransform;

	SegmentTransform.SetScale3D(GetNextSegmentScale(CurrentLocation));
	SegmentTransform.SetRotation(GetNextSegmentRotation(CurrentLocation));
	SegmentTransform.SetLocation(GetNextSegmentLocation(CurrentLocation));

	return SegmentTransform;
}

FVector AStroke::GetNextSegmentScale(FVector CurrentLocation) const
{
	FVector SegmentScale = CurrentLocation - PreviousCursor;

	return FVector( SegmentScale.Size(), 1, 1);
}

FQuat AStroke::GetNextSegmentRotation(FVector CurrentLocation) const
{
	FVector SegmentNormal = (CurrentLocation - PreviousCursor).GetSafeNormal();

	return FQuat::FindBetweenNormals(FVector::ForwardVector, SegmentNormal) ;
}

FVector AStroke::GetNextSegmentLocation(FVector CurrentLocation) const
{
	return GetTransform().InverseTransformPosition(PreviousCursor);
}

