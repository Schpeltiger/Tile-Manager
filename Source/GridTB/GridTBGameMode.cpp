// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GridTBGameMode.h"
#include "GridTBPlayerController.h"
#include "GridTBCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGridTBGameMode::AGridTBGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGridTBPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}