// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Picker.h"

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
	void SetParentPicker(APicker* newPicker);

protected: 
	//UPROPERTY(BlueprintReadonly, VisibleAnywhere)
	//	UTextBlock* SlotName;
	UPROPERTY()
		APicker* ParentPicker;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
		UButton* SlotButton;

	UPROPERTY(meta = (BindWidget))
		UImage* Thumbnail;

private:
	UFUNCTION()
		void OnClickButton();

	FString PaintName;
};
