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

	// 2초 마다 BlinkActor 스폰
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ABlinkSpawner::SpawnBlinkActor, 2.0f, true);
	
}

void ABlinkSpawner::SpawnBlinkActor()
{
    UWorld* World = GetWorld();
    if (!World) return;

    // 초기 위치, 회전은 Zero로 설정 후 Blink 함수에서 랜덤 위치 지정
    FVector SpawnLocation = FVector::ZeroVector;
    FRotator SpawnRotation = FRotator::ZeroRotator;

    ABlinkActor* NewActor = World->SpawnActor<ABlinkActor>(ABlinkActor::StaticClass(), SpawnLocation, SpawnRotation);
}
