// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	Box_Collision->SetBoxExtent(FVector(25.0f, 10.f, 10.f));

	RootComponent= Box_Collision;
	SM_Brick->SetupAttachment(Box_Collision);
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();

	// bind for overlaping event
	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABrick::DestroyBrick()
{
}


