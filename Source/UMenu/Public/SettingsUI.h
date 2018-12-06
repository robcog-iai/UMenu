// Copyright 2018, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "SlateBasics.h"
#include "MainMenuHUD.h"
#include "MenuGI.h"

// Lays out and controls the Main Menu UI for our tutorial.
class UMENU_API SSettingsUI : public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SSettingsUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MainMenuHUD)
		SLATE_END_ARGS()

	// Constructs and lays out the Main Menu UI Widget.
	// args Arguments structure that contains widget-specific setup information.
	void Construct(const FArguments& args);

	// Go back to the main menu ui
	FReply BackClicked();

	// Stores a weak reference to the HUD controlling this class.
	TWeakObjectPtr<class AMainMenuHUD> MainMenuHUD;

	// Style for the menu
	const struct FGlobalStyle* MenuStyle;

	// Is called when the text was changed
	void OnTextChanged(const FText & Text);

	// Is called when the button is clicked
	FReply ButtonClicked();

	// Is called when check box status changed
	void CheckBoxChanged(ECheckBoxState InCheckedState);

	// Is called to see if checkbox is currently checked
	ECheckBoxState IsBoxActive() const;
};