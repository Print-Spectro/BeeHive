// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFrog.h"
#include "BehaviorTree/BehaviorTree.h"

// Sets default values
AMyFrog::AMyFrog()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyFrog::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFrog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyFrog::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UBehaviorTree* AMyFrog::GetBehaviorTree() const
{
	return Tree;
}

