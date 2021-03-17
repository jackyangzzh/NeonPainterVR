// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "HandControllerBase.h"

#include "VRPawn.generated.h"

UCLASS()
class NEONPAINTERVR_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
 
private:
	void RightTriggerPressed() { if (RightPaintHandController) RightPaintHandController->TriggerPressed(); }
	void RightTriggerReleased() { if (RightPaintHandController) RightPaintHandController->TriggerReleased(); }

	void PageRightInput(float value);
	void UpdatePage(int32 Offset);

	// Config
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AHandControllerBase> PaintHandControllerClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AHandControllerBase> MenuHandControllerClass;

	UPROPERTY(EditDefaultsOnly)
		float PageThreshold = 0.85;

	// Components
	UPROPERTY(VisibleAnywhere)
		USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* Camera;

	FString CurrentSlotName;

	// Reference
	UPROPERTY()
		AHandControllerBase* RightPaintHandController;

	UPROPERTY()
		AHandControllerBase* LeftMenuHandController;

	int32 PreviousPageOffset = 0;
};
