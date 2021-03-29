// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "Picker.generated.h"

UCLASS()
class NEONPAINTERVR_API APicker : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APicker();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddPaint();
	void DeletePaint();

	void ToggleDeleteMode();
	void DeletePainting(FString SlotName);

	void UpdatePage(int32 Offset);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool GetDeleteMode() { return DeleteMode; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
		bool DeleteMode = false;

private:
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* PaintGrid;

	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* ActionBar;

	void LoadSlots();
	void LoadDots();

	int32 GetPageNumber() const;

	UPROPERTY(EditAnywhere)
		int32 CurrentPageIndex = 0;
};
