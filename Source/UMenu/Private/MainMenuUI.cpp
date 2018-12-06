// Copyright 2018, Institute for Artificial Intelligence - University of Bremen

#include "MainMenuUI.h"
#include "UMenu.h"
#include "GlobalMenuStyle.h" 
#include "MenuStyles.h" 


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuUI::Construct(const FArguments& args)
{
	MainMenuHUD = args._MainMenuHUD;
	MenuStyle = &FMenuStyles::Get().GetWidgetStyle<FGlobalStyle>("Global");

	ChildSlot
		[
			SNew(SOverlay)
			+SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		[
			SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
		.TextStyle(&MenuStyle->MenuButtonTextStyle)
		.Text(FText::FromString("Exit"))
		.OnClicked(this, &SMainMenuUI::ExitClicked)
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
	SNew(SVerticalBox)
	/*+ SVerticalBox::Slot()
		[
			SNew(SEditableTextBox)
			.Style(&MenuStyle->TextBox)
		.Text(FText::FromString("Kitchen"))
		.OnTextChanged_Raw(this, &SMainMenuUI::GetTextFromInput)
		]*/
	+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
		.TextStyle(&MenuStyle->MenuButtonTextStyle)
		.Text(FText::FromString("Open Map"))
		.OnClicked(this, &SMainMenuUI::CreateSessionClicked)
		]
	/*+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
		.TextStyle(&MenuStyle->MenuButtonTextStyle)
		.Text(FText::FromString("Join"))
		.OnClicked(this, &SMainMenuUI::JoinSessionClicked)
		]*/
	+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
		.TextStyle(&MenuStyle->MenuButtonTextStyle)
		.Text(FText::FromString("Settings"))
		.OnClicked(this, &SMainMenuUI::SettingsClicked)
		]
		]
		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


FReply SMainMenuUI::CreateSessionClicked()
{
	/*if (GEngine) 
	{
		try
		{
			
		}
		catch (const std::exception&)
		{

		}
	}*/
	MainMenuHUD->LoadMapList();
	return FReply::Handled();
}

FReply SMainMenuUI::JoinSessionClicked()
{
	MainMenuHUD->LoadServerList();

	return FReply::Handled();
}

void SMainMenuUI::GetTextFromInput(const FText & Text)
{
	/*if (GEngine)
	{
		try
		{
			
		}
		catch (const std::exception&)
		{

		}
	}*/
}

FReply SMainMenuUI::ExitClicked()
{
	FGenericPlatformMisc::RequestExit(false);
	return FReply::Handled();
}

FReply SMainMenuUI::SettingsClicked()
{
	MainMenuHUD->LoadSettings();
	return FReply::Handled();
}