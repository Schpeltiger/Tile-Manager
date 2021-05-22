// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\GridManager.h"
#include "Runtime/Engine/Classes/Engine/World.h"

// Sets default values
AGridManager::AGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TileScaling = 1.0;

	UBlueprint* Blueprint = Cast<UBlueprint>(GetClass()->ClassGeneratedBy);
	if (Blueprint) {
		Blueprint->bRunConstructionScriptOnDrag = false;
	}
}

// Called when the game starts or when spawned
void AGridManager::BeginPlay()
{
	Super::BeginPlay();
}

void AGridManager::PostEditChangeProperty(FPropertyChangedEvent& e)
{
	Super::PostEditChangeProperty(e);

	if (e.Property != NULL) {

		TArray<AActor*> temp;
		GetAttachedActors(temp);

		// auto iterate though all the actors you already have in the TArray
		for (auto CActor : temp)
		{
			CActor->Destroy();
		}

		const FName rows = FName(TEXT("NumRows"));
		const FName columns = FName(TEXT("NumColumns"));
		const FName spacing = FName(TEXT("TileScaling"));
		const FName scaling = FName(TEXT("TileSpacing"));

		if (e.Property->GetFName() == rows || e.Property->GetFName() == columns || e.Property->GetFName() == spacing || e.Property->GetFName() == scaling) {
			for (int row = 0; row < NumRows; row++) {
				for (int column = 0; column < NumColumns; column++) {

					FVector Location((100 * TileScaling + TileSpacing) * column, (100 * TileScaling + TileSpacing) * row, 0.0f);
					FRotator Rotation(0.0f, 0.0f, 0.0f);
					FActorSpawnParameters SpawnInfo;

					FTransform CurrentTransform(Location);
					AActor* NewTile = GetWorld()->SpawnActor<AActor>(Tile, CurrentTransform, SpawnInfo);
					NewTile->SetActorScale3D(FVector(TileScaling, TileScaling, TileScaling));

					(NewTile)->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
				}
			}
		}
	}
}

// Called every frame
void AGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

