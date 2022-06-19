// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_Player_Controller.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

APaddle_Player_Controller::APaddle_Player_Controller()
{	
}

void APaddle_Player_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
}

void APaddle_Player_Controller::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
}

void APaddle_Player_Controller::MoveHorizontal(float AxisValue)
{
}
