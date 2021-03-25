// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "SnapshotCamera.generated.h"

UCLASS()
class NEONPAINTERVR_API ASnapshotCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnapshotCamera();

	void Screenshot(const FString& Directory, const FString& FileName);


public:	
	UPROPERTY(VisibleAnywhere)
		USceneCaptureComponent2D* CaptureComponent;

};
