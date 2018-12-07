// Copyright 2018, Institute for Artificial Intelligence - University of Bremen

#include "ServerListUI.h"
#include "UMenu.h"
#include "GlobalMenuStyle.h" 
#include "MenuStyles.h" 

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SServerListUI::Construct(const FArguments& args)
{
	Sessions.Bind(this, &SServerListUI::GetSessions);
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
		.OnClicked(this, &SServerListUI::BackClicked)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)

		[

			SNew(SScrollBox)
			+ SScrollBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SAssignNew(Box, SVerticalBox)
		]
		]
		];
		/*	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Top)
		[
			SNew(STextBlock)
			.TextStyle(&MenuStyle->MenuTitleStyle)
		.Text(Sessions)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
		.TextStyle(&MenuStyle->MenuButtonTextStyle)
		.Text(FText::FromString("Find Session"))
		.OnClicked(this, &SServerListUI::FindSessionClicked)
		]
	+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
		.TextStyle(&MenuStyle->MenuButtonTextStyle)
		.Text(FText::FromString("Join"))
		.OnClicked(this, &SServerListUI::JoinGameClicked)
		]
		]*/

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SServerListUI::JoinGameClicked()
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
	return FReply::Handled();
}

FReply SServerListUI::FindSessionClicked()
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
	return FReply::Handled();
}

void SServerListUI::UpdateSessionsString(int i)
{
	SessionsString = "Sessions: " + FString::FromInt(i);
}

FText SServerListUI::GetSessions() const {
	return FText::FromString(SessionsString);
}

FReply SServerListUI::BackClicked()
{
	MainMenuHUD->LoadMainMenuFromServerList();
	return FReply::Handled();
}