// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyFrog.generated.h"

class UBehaviorTree;

UCLASS()
class BEEHIVE_API AMyFrog : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyFrog();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UBehaviorTree* GetBehaviorTree() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI", meta = (AllowPrivateAccess="true"))
	UBehaviorTree* Tree;
};
