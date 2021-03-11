// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaintGridCard.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "PaintGrid.generated.h"

/**
 * 
 */
UCLASS()
class NEONPAINTERVR_API UPaintGrid : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void AddPainting(int32 index, FString PaintName);

	void ClearPaint();
	
protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
		UUniformGridPanel* PaintGrid;

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UPaintGridCard> GridClass;
};
