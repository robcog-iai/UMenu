// Copyright 2018, Institute for Artificial Intelligence - University of Bremen

#include "MainMenuHUD.h"
#include "MainMenuUI.h"
#include "ServerListUI.h"
#include "CreateServerUI.h"
#include "SettingsUI.h"
#include "UMenu.h"
#include "Engine.h"

void AMainMenuHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SAssignNew(MainMenuUI, SMainMenuUI).MainMenuHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MainMenuUI.ToSharedRef()));
	}
	//MainMenuUI->SetVisibility(EVisibility::Hidden);
}

void AMainMenuHUD::LoadServerList() 
{
	MainMenuUI->SetVisibility(EVisibility::Hidden);
	SAssignNew(ServerListUI, SServerListUI).MainMenuHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(ServerListUI.ToSharedRef()));
	}
}

void AMainMenuHUD::LoadMapList()
{
	MainMenuUI->SetVisibility(EVisibility::Hidden);
	SAssignNew(CreateServerUI, SCreateServerUI).MainMenuHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(CreateServerUI.ToSharedRef()));
	}
}

void AMainMenuHUD::LoadSettings()
{
	MainMenuUI->SetVisibility(EVisibility::Hidden);
	SAssignNew(SettingsUI, SSettingsUI).MainMenuHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(SettingsUI.ToSharedRef()));
	}
}

void AMainMenuHUD::LoadMainMenuFromServerList()
{
	ServerListUI->SetVisibility(EVisibility::Hidden);
	MainMenuUI->SetVisibility(EVisibility::Visible);
}

void AMainMenuHUD::LoadMainMenuFromCreateServer()
{
	CreateServerUI->SetVisibility(EVisibility::Hidden);
	MainMenuUI->SetVisibility(EVisibility::Visible);
}

void AMainMenuHUD::LoadMainMenuFromSettings()
{
	SettingsUI->SetVisibility(EVisibility::Hidden);
	MainMenuUI->SetVisibility(EVisibility::Visible);
}

void AMainMenuHUD::GiveSessionsNumber(int i)
{
	ServerListUI->UpdateSessionsString(i);
}

void AMainMenuHUD::MakeVisible()
{
	MainMenuUI->SetVisibility(EVisibility::Visible);
}

void AMainMenuHUD::MakeHidden()
{
	MainMenuUI->SetVisibility(EVisibility::Hidden);
}