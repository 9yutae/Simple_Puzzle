#include "BlinkActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"

ABlinkActor::ABlinkActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ScenRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Pipe.Shape_Pipe"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Power_Sphere.M_Power_Sphere"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	SetActorScale3D(FVector(0.5f, FMath::RandRange(1.f, 2.f), 0.5f));

	// 월드 내 생성 범위 제한
	MinLocationRange = -1000.f;
	MaxLocationRange = 1000.f;
	MinHeight = 50.f;
	MaxHeight = 300.f;

	// 랜덤 지속 시간 제한
	MinDuration = 1.f;
	MaxDuration = 10.f;

	// 랜덤 이동 속도 제한
	MinSpeed = 20.f;
	MaxSpeed = 500.f;
}

void ABlinkActor::BeginPlay()
{
	Super::BeginPlay();

	Blink();
}

void ABlinkActor::Blink()
{
	// 월드에서 랜덤한 위치에 생성
	FVector RandomLocation = FVector(
		FMath::RandRange(MinLocationRange, MaxLocationRange),
		FMath::RandRange(MinLocationRange, MaxLocationRange),
		FMath::RandRange(MinHeight, MaxHeight)
	);
	SetActorLocation(RandomLocation);

	// 랜덤 지속 시간 설정
	float RandomDuration = FMath::RandRange(MinDuration, MaxDuration);

	// 랜덤 이동 방향 설정
	FVector RandomDirection = UKismetMathLibrary::RandomUnitVector();

	// 랜덤한 속도	
	float RandomSpeed = FMath::RandRange(MinSpeed, MaxSpeed);
	Velocity = RandomDirection * RandomSpeed;

	// 이동 방향을 향하도록 액터 회전
	FRotator NewRotation = FRotationMatrix::MakeFromY(Velocity).Rotator();
	SetActorRotation(NewRotation);

	// 랜덤 시간 이후 액터 제거
	GetWorldTimerManager().SetTimer(DestroyTimerHandle, this, &ABlinkActor::DestroyActor, RandomDuration, true);
}

void ABlinkActor::DestroyActor()
{
	Destroy();
}

void ABlinkActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// DeltaTime을 이용한 액터 이동
	SetActorLocation(GetActorLocation() + Velocity * DeltaTime);

	if (GetActorLocation().Z <= 0 || GetActorLocation().Z > 5000)
	{
		Velocity.Z *= -1;

		// 이동 방향을 향하도록 액터 회전
		FRotator NewRotation = FRotationMatrix::MakeFromY(Velocity).Rotator();
		SetActorRotation(NewRotation);

	}
}
