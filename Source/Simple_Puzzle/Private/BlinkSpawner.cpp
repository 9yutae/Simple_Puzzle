#include "BlinkSpawner.h"
#include "Simple_Puzzle/Public/BlinkActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"

ABlinkSpawner::ABlinkSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABlinkSpawner::BeginPlay()
{
	Super::BeginPlay();

	// 2�� ���� BlinkActor ����
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ABlinkSpawner::SpawnBlinkActor, 2.0f, true);
	
}

void ABlinkSpawner::SpawnBlinkActor()
{
    UWorld* World = GetWorld();
    if (!World) return;

    // �ʱ� ��ġ, ȸ���� Zero�� ���� �� Blink �Լ����� ���� ��ġ ����
    FVector SpawnLocation = FVector::ZeroVector;
    FRotator SpawnRotation = FRotator::ZeroRotator;

    ABlinkActor* NewActor = World->SpawnActor<ABlinkActor>(ABlinkActor::StaticClass(), SpawnLocation, SpawnRotation);
}
