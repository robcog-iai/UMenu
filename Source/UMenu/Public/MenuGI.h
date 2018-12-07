// Copyright 2017, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UMenu.h"
#include "MenuGI.generated.h"

/**
 * 
 */
UCLASS()
class UMENU_API UMenuGI : public UGameInstance
{
	GENERATED_BODY()
	
public:

	// Finds a session
	UFUNCTION(BlueprintImplementableEvent)
	void FindSessionEvent();

	// Joins a session
	UFUNCTION(BlueprintImplementableEvent)
	void JoinSessionEvent();

	// Opens a map
	UFUNCTION(BlueprintImplementableEvent)
	void OpenMap();

	// Map name
	UPROPERTY(BlueprintReadWrite)
	FString Map;

	// VR mode on/off
	UPROPERTY(BlueprintReadWrite)
	bool bVRMode;

	// Multiplayer on/off
	UPROPERTY(BlueprintReadWrite)
	bool bMultiplayer;

	// List of found sessions
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> FoundSession;
};
