// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Paddle"));
	RootComponent = SM_Paddle;

	SM_Paddle->SetEnableGravity(false);
	
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Paddle->SetCollisionProfileName(TEXT("PhysicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
	// constraint the paddle movement on Z and X
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APaddle::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.f, 0.f),1.f, false);
}

