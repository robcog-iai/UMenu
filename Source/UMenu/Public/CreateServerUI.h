// Copyright 2018, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "SlateBasics.h"
#include "MainMenuHUD.h"
#include "MenuGI.h"

// Lays out and controls the Main Menu UI for our tutorial.
class UMENU_API SCreateServerUI : public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SCreateServerUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MainMenuHUD)
		SLATE_END_ARGS()

	// Constructs and lays out the Main Menu UI Widget.
	// args Arguments structure that contains widget-specific setup information.
	void Construct(const FArguments& args);

	// Stores a weak reference to the HUD controlling this class.
	TWeakObjectPtr<class AMainMenuHUD> MainMenuHUD;

	// Style for the menu
	const struct FGlobalStyle* MenuStyle;

	// Called when the back button was clicked
	FReply BackClicked();

	// Box will later display the list of maps
	TSharedPtr<SVerticalBox> Box;

	// Pulls the map names out of the projects map folder
	TArray<FString> GetAllMapNames();

	// List of map names
	TArray<FString> Maps;

	// Adds the maps to the Box so they are shown in the UI
	void AddMapsToList();

	// Opens the map that was clicked 
	FReply OpenMapClicked(FString MapName);

	// Called when the checkboxs status was changed
	void VRCheckBoxChanged(ECheckBoxState InCheckedState);

	// Called to get the current status of the checkbox
	ECheckBoxState IsVRBoxActive() const;
};