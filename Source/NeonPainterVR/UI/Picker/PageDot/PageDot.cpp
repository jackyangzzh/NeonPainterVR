// Fill out your copyright notice in the Description page of Project Settings.

#include "PageDot.h"

void UPageDot::SetActive(bool Active)
{
    if (Active)
    {
        PageDotImage->SetOpacity(1);
    }
    else
    {
        PageDotImage->SetOpacity(DisabledOpacity);
    }
}