// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHandController.h"

AMenuHandController::AMenuHandController()
{
    Menu = CreateDefaultSubobject<UWidgetComponent>(TEXT("HandMenu"));
    Menu->SetupAttachment(GetRootComponent());
}