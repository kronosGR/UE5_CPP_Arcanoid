// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Paddle_Player_Controller.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "BallBound.generated.h"

UCLASS()
class UE5_CPP_ARCANOID_API ABallBound : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallBound();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent*  Box_Collision;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType
		, bool bFromSweep, const FHitResult& SweepResult);

	APaddle_Player_Controller* PlayerController_REF;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
