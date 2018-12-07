// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuGameMode.h"
#include "UMenu.h"
#include "MainMenuHUD.h"

AMenuGameMode::AMenuGameMode()
{
	HUDClass = AMainMenuHUD::StaticClass();
}


