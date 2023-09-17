// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Frog_AIController.generated.h"

/**
 * 
 */
UCLASS()
class BEEHIVE_API AFrog_AIController : public AAIController
{
	GENERATED_BODY()
	public:
		explicit AFrog_AIController(FObjectInitializer const& ObjectInitializer);

	protected:
		virtual void OnPossess(APawn* InPawn) override;
};
