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

void UActionBar::OnAddButtonClick()
{
    UE_LOG(LogTemp, Warning, TEXT("Add Button"));
}

void UActionBar::OnDeleteButtonClick()
{
    UE_LOG(LogTemp, Warning, TEXT("Delete Button"));
}