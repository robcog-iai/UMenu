// Copyright 2018, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class UMENU_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()
	// Initializes the Slate UI and adds it as widget content to the game viewport.
	virtual void PostInitializeComponents() override;

	// Reference to the Main Menu Slate UI.
	TSharedPtr<class SMainMenuUI> MainMenuUI;

	// Reference to the Main Menu Slate UI.
	TSharedPtr<class SServerListUI> ServerListUI;

	// Reference to the Main Menu Slate UI.
	TSharedPtr<class SCreateServerUI> CreateServerUI;

	// Reference to the Main Menu Slate UI.
	TSharedPtr<class SSettingsUI> SettingsUI;

	// Reference to the Main Menu Slate UI.
	TSharedPtr<class SIngameUI> IngameListUI;

public:
	// Load server list ui
	void LoadServerList();

	// Load map list ui
	void LoadMapList();

	// Load settings ui
	void LoadSettings();

	// Go back to the main menu ui
	void LoadMainMenuFromServerList();

	// Go back to the main menu ui
	void LoadMainMenuFromCreateServer();

	// Go back to the main menu ui
	void LoadMainMenuFromSettings();

	/**
	Tells the UI how many sessions have been found
	@param i - number of found sessions
	*/
	UFUNCTION(BlueprintCallable)
	void GiveSessionsNumber(int i);

	// Makes the UI visible
	UFUNCTION(BlueprintCallable)
	void MakeVisible();

	// Makes the UI hidden
	UFUNCTION(BlueprintCallable)
	void MakeHidden();
};
