#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class SIMPLE_PUZZLE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Movement")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Movement")
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Movement")
	FVector MaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Movement")
	float Threshold;

public:	
	virtual void Tick(float DeltaTime) override;

};
