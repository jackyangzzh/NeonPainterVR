// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Picker.h"
#include "ActionBar.generated.h"

/**
 * 
 */
UCLASS()
class NEONPAINTERVR_API UActionBar : public UUserWidget
{
	GENERATED_BODY()

public:
	bool Initialize() override;

	void SetParentPicker(APicker *newPicker);

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UButton* AddButton;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UButton* DeleteButton;

private:
	UFUNCTION()
		void OnAddButtonClick();
	
	UFUNCTION()
		void OnDeleteButtonClick();

	UPROPERTY()
		APicker* ParentPicker;
};
