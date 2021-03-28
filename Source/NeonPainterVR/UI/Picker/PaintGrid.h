// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaintGridCard.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/HorizontalBox.h"
#include "PageDot/PageDot.h"
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
	void ClearDots();

	void AddPageDot(bool active);
	void SetParentPicker(APicker* newPicker);

	int32 GetSlotNumber() const;
	
protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
		UUniformGridPanel* PaintGrid;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
		UHorizontalBox* PageDots;

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UPaintGridCard> GridClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UPageDot> PageDotClass;

	UPROPERTY(EditDefaultsOnly)
		float PageDotPadding = 10;

	UPROPERTY()
		APicker* ParentPicker;
};
