// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/Button.h"
#include "InGameMenu.h"

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(Cancel_B != nullptr))return false;
	Cancel_B->OnClicked.AddDynamic(this, &UInGameMenu::CancelPressed);

	if (!ensure(Quit_B != nullptr))return false;
	Quit_B->OnClicked.AddDynamic(this, &UInGameMenu::QuitPressed);

	return true;
}

void UInGameMenu::CancelPressed()
{
	Teardown();
}

void UInGameMenu::QuitPressed()
{
	if (MenuInterface != nullptr)
	{
		Teardown();
		MenuInterface->LoadMainMenu();
	}
}
