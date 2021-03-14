// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "PageDot.generated.h"

/**
 * 
 */
UCLASS()
class NEONPAINTERVR_API UPageDot : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetActive(bool Active);

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UImage* PageDotImage;

private:
	UPROPERTY(EditDefaultsOnly)
		float DisabledOpacity = 0.5;
};
