// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"
#include "Components/WidgetInteractionComponent.h"

#include "UIHandController.generated.h"

/**
 * 
 */
UCLASS()
class NEONPAINTERVR_API AUIHandController : public AHandControllerBase
{
	GENERATED_BODY()

public:
	AUIHandController();

	void TriggerPressed() override;
	void TriggerReleased() override;

private: 
	UPROPERTY(VisibleAnywhere)
		UWidgetInteractionComponent* Pointer;
	
};
