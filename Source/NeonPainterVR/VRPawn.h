// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"

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

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AHandController> HandController;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* VRroot;
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* Camera;

	UPROPERTY()
		AHandController* RightController;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
