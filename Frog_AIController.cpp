// Fill out your copyright notice in the Description page of Project Settings.


#include "Frog_AIController.h"
#include "MyFrog.h"
#include "BehaviorTree/BehaviorTree.h"


AFrog_AIController::AFrog_AIController(FObjectInitializer const& ObjectInitializer)
{

}

void AFrog_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (AMyFrog* const  npc = Cast<AMyFrog>(InPawn)) {
		if (UBehaviorTree* const tree = npc->GetBehaviorTree()) {
			UBlackboardComponent* b;
			UseBlackboard(tree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(tree);
		}
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("Cast to pawn failed"));
	}

}
