// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "DebugPawn.generated.h"

UCLASS()
class UE4CAPTURE2DBENCH_API ADebugPawn : public ADefaultPawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	USceneCaptureComponent2D* Capture2DComponent;

	// Sets default values for this pawn's properties
	ADebugPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
};
