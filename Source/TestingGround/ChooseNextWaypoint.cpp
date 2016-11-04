// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGround.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	// get patrol points
	UPatrolRoute* PatrolRoute = OwnerComp.GetAIOwner()->GetControlledPawn()->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
	
	// set next waypoint

	TArray<AActor*> PatrolPoints = PatrolRoute->GetPatrolPoints();

	if (PatrolPoints.Num() == 0) { return EBTNodeResult::Failed; }

	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName)]);

	////cycle
	int32 newIndex = (BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName) + 1) % PatrolPoints.Num();

	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, newIndex);

	return EBTNodeResult::Succeeded;
}