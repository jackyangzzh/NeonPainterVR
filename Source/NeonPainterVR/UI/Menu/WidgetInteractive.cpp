// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetInteractive.h"

void UWidgetInteractive::TickComponent(float deltaTime, enum ELevelTick tickType, FActorComponentTickFunction *tickFunction)
{
    Super::TickComponent(deltaTime, tickType, tickFunction);

    if(IsOverInteractableWidget() && !isClicked)
    {
        PressPointerKey(EKeys::LeftMouseButton);
        isClicked = true;
    }
    if (!IsOverInteractableWidget() && isClicked)
    {
        ReleasePointerKey(EKeys::LeftMouseButton);
        isClicked = false;
    }
}