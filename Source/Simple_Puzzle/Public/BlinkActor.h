#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlinkActor.generated.h"

UCLASS()
class SIMPLE_PUZZLE_API ABlinkActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABlinkActor();

protected:
	virtual void BeginPlay() override;

	void SpawnBlinkActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkActor|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkActor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkActor|Movement")
	float MinLocationRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkActor|Movement")
	float MaxLocationRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkActor|Movement")
	float MinHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkActor|Movement")
	float MaxHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkActor|Movement")
	float MinDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkActor|Movement")
	float MaxDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkActor|Movement")
	float MinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlinkActor|Movement")
	float MaxSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BlinkActor|Movement")
	FVector Velocity;

	UFUNCTION(BlueprintCallable, Category = "BlinkActor|Movement")
	void Blink();

	UFUNCTION(BlueprintCallable, Category = "BlinkActor|Movement")
	void DestroyActor();

public:
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle DestroyTimerHandle;

};
