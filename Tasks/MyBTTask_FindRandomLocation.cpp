// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_FindRandomLocation.h"

//ai controller in the folder above
#include "../Frog_AIController.h"

//navigation system
#include "NavigationSystem.h"

//blackboard
#include "BehaviorTree/BlackboardComponent.h"

UMyBTTask_FindRandomLocation::UMyBTTask_FindRandomLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find Random Location In NavMesh";
}

EBTNodeResult::Type UMyBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{	

	Super::ExecuteTask(OwnerComp, NodeMemory);
	//get AI controller and pawn
	if (AFrog_AIController* const cont = Cast<AFrog_AIController>(OwnerComp.GetAIOwner())) 
	{
		if (APawn* const FROG = cont->GetPawn()) 
		{
			//get pawn location as origin for random search
			FVector Origin = FROG->GetActorLocation();

			//get navigation system and generate randon location 
			if (UNavigationSystemV1* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld())) {
				FNavLocation NavLoc;
				if (NavSys->GetRandomPointInNavigableRadius(Origin, SearchRadius, NavLoc))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), NavLoc.Location);

				}
				// finish with success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
