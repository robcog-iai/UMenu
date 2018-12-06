// Copyright 2018, Institute for Artificial Intelligence - University of Bremen

#include "SettingsUI.h"
#include "UMenu.h"
#include "GlobalMenuStyle.h" 
#include "MenuStyles.h" 
#include "Engine.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSettingsUI::Construct(const FArguments& args)
{
	MainMenuHUD = args._MainMenuHUD;
	MenuStyle = &FMenuStyles::Get().GetWidgetStyle<FGlobalStyle>("Global");

	ChildSlot
		[
		SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Top)
			[
				SNew(SButton)
				.ButtonStyle(&MenuStyle->MenuButtonStyle)
				.TextStyle(&MenuStyle->MenuButtonTextStyle)
				.Text(FText::FromString("Back"))
				.OnClicked(this, &SSettingsUI::BackClicked)
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SVerticalBox)
					// Example for a changeable text
					+ SVerticalBox::Slot()
					[
						SNew(SEditableTextBox)
						.Style(&MenuStyle->TextBox)
						.Text(FText::FromString("StringExample"))
						.OnTextChanged_Raw(this, &SSettingsUI::OnTextChanged)
					]
					// Example for a button
					+SVerticalBox::Slot()
					[
						SNew(SButton)
						.ButtonStyle(&MenuStyle->MenuButtonStyle)
						.TextStyle(&MenuStyle->MenuButtonTextStyle)
						.Text(FText::FromString("ButtonExample"))
						.OnClicked(this, &SSettingsUI::ButtonClicked)
					]
					// Example for a checkbox 
					+ SVerticalBox::Slot()
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(SCheckBox)
							.IsChecked(this, &SSettingsUI::IsBoxActive)
							.OnCheckStateChanged_Raw(this, &SSettingsUI::CheckBoxChanged)
						]
						+ SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.AutoWidth()
						[
							SNew(STextBlock)
							.Text(FText::FromString("VR"))
							.TextStyle(&MenuStyle->MenuButtonTextStyle)
						]
					]
			]
		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


FReply SSettingsUI::BackClicked()
{
	MainMenuHUD->LoadMainMenuFromSettings();
	return FReply::Handled();
}

// Is called when the text was changed
void  SSettingsUI::OnTextChanged(const FText & Text)
{
	// insert code that does something with the new text
	// you could save it in this class, call a function in another class etc. 
}

// Is called when the button is clicked
FReply SSettingsUI::ButtonClicked()
{
	// insert code to run on buton press
	//

	return FReply::Handled();
}

// Is called when check box status changed
void SSettingsUI::CheckBoxChanged(ECheckBoxState InCheckedState)
{
	if (GEngine)
	{
		try
		{
			if (InCheckedState == ECheckBoxState::Checked)
			{
				Cast<UMenuGI>(((UGameEngine*)GEngine)->GameInstance)->bVRMode = true;
			}
			else
			{
				Cast<UMenuGI>(((UGameEngine*)GEngine)->GameInstance)->bVRMode = false;
			}
		}
		catch (const std::exception&)
		{

		}
	}
}

// Is called to see if checkbox is currently checked
ECheckBoxState SSettingsUI::IsBoxActive() const
{
	if (GEngine)
	{
		try
		{
			if (Cast<UMenuGI>(((UGameEngine*)GEngine)->GameInstance)->bVRMode)
			{
				return ECheckBoxState::Checked;
			}
			else
			{
				return ECheckBoxState::Unchecked;
			}
		}
		catch (const std::exception&)
		{

		}
	}
	return ECheckBoxState::Unchecked;
}