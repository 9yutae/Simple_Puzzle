#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlinkSpawner.generated.h"

UCLASS()
class SIMPLE_PUZZLE_API ABlinkSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ABlinkSpawner();

protected:
	virtual void BeginPlay() override;

	void SpawnBlinkActor();

private:
	FTimerHandle SpawnTimerHandle;

};
