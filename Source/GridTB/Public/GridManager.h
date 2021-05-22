// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridManager.generated.h"

UCLASS()
class GRIDTB_API AGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid Attributes", meta = (ExposeOnSpawn = "true"))
	int NumRows;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid Attributes", meta = (ExposeOnSpawn = "true"))
	int NumColumns;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid Attributes", meta = (ExposeOnSpawn = "true"))
	float TileSpacing;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grid Attributes", meta = (ExposeOnSpawn = "true"))
	float TileScaling;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<AActor> Tile;

public:	

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
