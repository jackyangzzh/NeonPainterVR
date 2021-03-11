// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../HandControllerBase.h"
#include "Components/WidgetComponent.h"
#include "MenuHandController.generated.h"

/**
 * 
 */
UCLASS()
class NEONPAINTERVR_API AMenuHandController : public AHandControllerBase
{
	GENERATED_BODY()

public:
	AMenuHandController();

private:
	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* Menu;
};
