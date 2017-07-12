// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Capture2DBench.h"
#include "DebugPawn.h"


// Sets default values
ADebugPawn::ADebugPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADebugPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADebugPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Tick"));
}

// Called to bind functionality to input
void ADebugPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

