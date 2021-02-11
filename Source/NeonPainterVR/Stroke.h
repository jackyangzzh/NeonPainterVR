// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Saving/NeonPainterSaveGame.h"

#include "Stroke.generated.h"

UCLASS()
class NEONPAINTERVR_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStroke();

	void Update(FVector CursorLocation);

	FStrokeState SerializeToStruct() const;
	static AStroke* DeserializeFromStruct(UWorld* World, const FStrokeState& StrokeState);

private:

	FTransform GetNextSegmentTransform(FVector CurrentLocation) const;

	FTransform GetNextJointTransform(FVector CurrentLocation) const;

	FVector GetNextSegmentScale(FVector CurrentLocation) const;
	FQuat GetNextSegmentRotation(FVector CurrentLocation) const;
	FVector GetNextSegmentLocation(FVector CurrentLocation) const;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		UInstancedStaticMeshComponent* StrokeMesh;

	UPROPERTY(VisibleAnywhere)
		UInstancedStaticMeshComponent* JointMesh;

	FVector PreviousCursor;
	TArray<FVector> ControlPoints;
};
