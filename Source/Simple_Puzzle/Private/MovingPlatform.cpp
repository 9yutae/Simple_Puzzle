#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ScenRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Brick_Cut_Stone.M_Brick_Cut_Stone"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	Velocity = FVector::OneVector;
	MaxRange = FVector::OneVector * 1000.0f;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	Velocity *= -1;
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Threshold = Velocity.Size() * 0.025;

	FVector CurrentLocation = GetActorLocation();
	if ((StartLocation + MaxRange - CurrentLocation).SizeSquared() < Threshold
		|| (StartLocation - CurrentLocation).SizeSquared() < Threshold)
	{
		Velocity *= -1;
	}
	
	if (!FMath::IsNearlyZero(Velocity.Length()))
	{
		AddActorWorldOffset(Velocity * DeltaTime);
	}
}
