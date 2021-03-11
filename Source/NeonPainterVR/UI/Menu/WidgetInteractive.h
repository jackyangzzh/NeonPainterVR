// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetInteractionComponent.h"
#include "WidgetInteractive.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class NEONPAINTERVR_API UWidgetInteractive : public UWidgetInteractionComponent
{
	GENERATED_BODY()

public: 
	void TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction* tickFunction) override;

private:
	bool isClicked = false;
};
