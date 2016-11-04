// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUND_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*> GetPatrolPoints() const;

private:	
	UPROPERTY(EditAnywhere)
	TArray<AActor*> PatrolPoints;
	
};