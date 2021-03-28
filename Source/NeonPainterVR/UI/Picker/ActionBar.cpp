// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionBar.h"

bool UActionBar::Initialize()
{
    if(!Super::Initialize()) return false;

    if(!AddButton) return false;
    AddButton->OnClicked.AddDynamic(this, &UActionBar::OnAddButtonClick);

    if (!DeleteButton) return false;
    DeleteButton->OnClicked.AddDynamic(this, &UActionBar::OnDeleteButtonClick);

    return true;
}

void UActionBar::SetParentPicker(APicker* newPicker)
{
    ParentPicker = newPicker;
}

void UActionBar::OnAddButtonClick()
{
    if(ParentPicker)
    {
        ParentPicker->AddPaint();
    }
}

void UActionBar::OnDeleteButtonClick()
{
    if(ParentPicker)
    {
        ParentPicker->ToggleDeleteMode();
    }
}