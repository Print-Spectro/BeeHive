// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Frog_AIController.generated.h"


/**
 * 
 */
 struct FAIStimulus;

UCLASS()
class BEEHIVE_API AFrog_AIController : public AAIController
{
	GENERATED_BODY()
public:
		explicit AFrog_AIController(FObjectInitializer const& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	float SightRadius = 500.f;


	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	float FOV = 90.f;

	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	float PerceptionDuration = 3.f;

	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	float MaximumMoveDistance = 520.f;

	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	bool DetectFriendlies = true;

	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	bool DetectEnemies = true;

	UPROPERTY(EditDefaultsOnly, Category = "Defaults")
	bool DetectNeutrals = true;

private:
	class UAISenseConfig_Sight* SightConfig;

	void SetupPerceptionSystem();

	UFUNCTION()
	void OnTargetDetected(AActor*Actor, FAIStimulus const Stimulus);

};
