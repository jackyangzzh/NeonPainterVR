// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
		void AddPainting();
	
protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
		UUniformGridPanel* PaintGrid;

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UUserWidget> GridClass;
};
