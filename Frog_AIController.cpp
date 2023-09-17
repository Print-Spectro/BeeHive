// Fill out your copyright notice in the Description page of Project Settings.


#include "Frog_AIController.h"
#include "MyFrog.h"
#include "MyBeeCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

//AI stimulus
#include <Perception/AIPerceptionTypes.h>
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"


AFrog_AIController::AFrog_AIController(FObjectInitializer const& ObjectInitializer)
{
	SetupPerceptionSystem();
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
		else {
			UE_LOG(LogTemp, Warning, TEXT("AFrog_AIController::OnPossess couldn't get behaviour tree"));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Cast to pawn failed"));
	}

}

void AFrog_AIController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	if (SightConfig) {
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent")));
		SightConfig->SightRadius = SightRadius;
		SightConfig->LoseSightRadius = SightRadius + 50.f;
		SightConfig->PeripheralVisionAngleDegrees = FOV;
		SightConfig->SetMaxAge(PerceptionDuration);
		SightConfig->AutoSuccessRangeFromLastSeenLocation = MaximumMoveDistance;
		SightConfig->DetectionByAffiliation.bDetectEnemies = DetectEnemies;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = DetectFriendlies;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = DetectNeutrals;


		GetPerceptionComponent()->SetDominantSense(SightConfig->GetSenseImplementation());
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AFrog_AIController::OnTargetDetected);
		GetPerceptionComponent()->ConfigureSense(*SightConfig);

	}
}

void AFrog_AIController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	if (auto* const ch = Cast<AMyBeeCharacter>(Actor)) {
		GetBlackboardComponent()->SetValueAsBool("CanSeePlayer", Stimulus.WasSuccessfullySensed());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Cast to AMYFrog failed"));
	}
}
