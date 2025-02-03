#include "RotatingPlatform.h"

ARotatingPlatform::ARotatingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ScenRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Plane.Shape_Plane"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Brick_Cut_Stone.M_Brick_Cut_Stone"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	StartLocation = FVector::ZeroVector;
	RotationSpeed = 1.0f;
	Radius = 100.0f;
}

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Radian += (RotationSpeed * DeltaTime);
	if (Radian > 2 * PI)
		Radian -= 2 * PI;

	FVector newLocation = FVector(FMath::Cos(Radian) * Radius,
		FMath::Sin(Radian) * Radius, GetActorLocation().Z);
	SetActorLocation(newLocation);
}

