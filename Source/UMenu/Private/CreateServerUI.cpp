// Copyright 2018, Institute for Artificial Intelligence - University of Bremen

#include "CreateServerUI.h"
#include "UMenu.h"
#include "GlobalMenuStyle.h" 
#include "MenuStyles.h" 
#include "Runtime/Engine/Classes/Engine/ObjectLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Engine.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SCreateServerUI::Construct(const FArguments& args)
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
		.OnClicked(this, &SCreateServerUI::BackClicked)
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
			+ SOverlay::Slot()
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Bottom)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
				[
					SNew(SCheckBox)	
					.IsChecked(this, &SCreateServerUI::IsVRBoxActive)
					.OnCheckStateChanged_Raw(this, &SCreateServerUI::VRCheckBoxChanged)
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
		];

	Maps = GetAllMapNames();
	AddMapsToList();

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SCreateServerUI::BackClicked()
{
	MainMenuHUD->LoadMainMenuFromCreateServer();
	return FReply::Handled();
}

void SCreateServerUI::AddMapsToList()
{
	for(FString s:Maps)
	{
		TSharedPtr<SButton> TmpButton;
		TmpButton = SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
			.TextStyle(&MenuStyle->MenuButtonTextStyle)
			.Text(FText::FromString(s))
			.OnClicked(this, &SCreateServerUI::OpenMapClicked,s);
		Box->AddSlot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.AutoHeight()
			[
				TmpButton.ToSharedRef()
			];
	}
}

TArray<FString> SCreateServerUI::GetAllMapNames()
{
	auto ObjectLibrary = UObjectLibrary::CreateLibrary(UWorld::StaticClass(), false, true);
	ObjectLibrary->LoadAssetDataFromPath(TEXT("/Game/Maps"));
	TArray<FAssetData> AssetDatas;
	ObjectLibrary->GetAssetDataList(AssetDatas);
	UE_LOG(LogTemp, Warning, TEXT("Found maps: %d"), AssetDatas.Num());

	TArray<FString> Names = TArray<FString>();

	for (int32 i = 0; i < AssetDatas.Num(); ++i)
	{
		FAssetData& AssetData = AssetDatas[i];

		auto name = AssetData.AssetName.ToString();
		Names.Add(name);
	}
	return Names;
}

FReply SCreateServerUI::OpenMapClicked(FString MapName)
{
	if (GEngine)
	{
		try
		{
			Cast<UMenuGI>(((UGameEngine*)GEngine)->GameInstance)->Map=MapName;
			Cast<UMenuGI>(((UGameEngine*)GEngine)->GameInstance)->OpenMap();
		}
		catch (const std::exception&)
		{

		}
	}
	return FReply::Handled();
}

void SCreateServerUI::VRCheckBoxChanged(ECheckBoxState InCheckedState)
{
	if (GEngine)
	{
		try
		{
			if (InCheckedState== ECheckBoxState::Checked)
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

ECheckBoxState SCreateServerUI::IsVRBoxActive() const
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