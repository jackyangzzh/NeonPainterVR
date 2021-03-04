// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "PaintGridCard.generated.h"

/**
 * 
 */
UCLASS()
class NEONPAINTERVR_API UPaintGridCard : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetPaintingName(FString PaintingName);

protected: 
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
		UTextBlock* SlotName;
};
