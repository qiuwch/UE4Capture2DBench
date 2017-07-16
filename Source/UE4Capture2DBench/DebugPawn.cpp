// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Capture2DBench.h"
#include "DebugPawn.h"


// Sets default values
ADebugPawn::ADebugPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capture2DComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Capture2DComponent"));
	// this->SetRootComponent(FaceComponent);
	Capture2DComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);


	Capture2DComponent->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
	Capture2DComponent->TextureTarget = NewObject<UTextureRenderTarget2D>();
	Capture2DComponent->TextureTarget->InitAutoFormat(640, 480);

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
	
	TArray<FColor> ImageData;
	int32 Width, Height;
	// Read information for the SceneCaptureComponent2D
	UTextureRenderTarget2D* RenderTarget = Capture2DComponent->TextureTarget;
	FTextureRenderTargetResource* RenderTargetResource;
	ImageData.AddZeroed(RenderTarget->SizeX * RenderTarget->SizeY);
	RenderTargetResource = RenderTarget->GameThread_GetRenderTargetResource();

	FReadSurfaceDataFlags ReadSurfaceDataFlags;
	ReadSurfaceDataFlags.SetLinearToGamma(false);
	// This ReadSurfaceDataFlags is super important, must disable SetLinearToGamma for image capture!
	// Instead of using this flag, we will set the gamma to the correct value directly
	RenderTargetResource->ReadPixels(ImageData, ReadSurfaceDataFlags);
	Width = RenderTarget->SizeX;
	Height = RenderTarget->SizeY;
}

// Called to bind functionality to input
void ADebugPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

