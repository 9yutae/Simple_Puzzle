# 🎮 Simple_Puzzle

## 📌 프로젝트 개요
본 프로젝트는 팀스파르타코딩클럽 내일배움캠프의 'Unreal 기반 3D 게임 개발자 양성과정' 2기   
Ch03의 6번 과제에 대한 소스 코드입니다.   
- 프로젝트 기간 : 2025.01.20 ~ 2025.02.05
</br>

## 🎯 필수 기능
✅ 1. C++ Actor 클래스 구현
   - 2개 이상의 C++ 기반 Actor 클래스를 생성
   - 각각 `StaticMeshComponent`를 포함하여 맵에서 시각적으로 배치 가능

✅ 2. Tick 함수 기반 동적 Transform 변경
   - `Tick(float DeltaTime)`을 활용하여 회전 또는 이동 구현
   - 회전 발판: `AddActorLocalRotation()`을 사용하여 지속적으로 회전
   - 이동 플랫폼: `SetActorLocation()`을 활용해 왕복 이동 로직 구현
   - 프레임 독립성을 유지하기 위해 `DeltaTime`을 적용

✅ 3. 리플렉션 시스템 적용
   - `UPROPERTY`를 사용하여 속도, 이동 범위, 회전 값을 에디터에서 조정 가능하게 노출
   - `EditAnywhere`, `BlueprintReadWrite`, `Category` 등을 적절히 활용하여 Details 패널에서 실시간 수정 가능
</br>

## 🏆 도전 과제
🔥 1. 시간 제한 및 카운트다운
   - `FTimerHandle`을 활용하여 특정 시간 후 발판이 사라지거나 위치 변경.
   - `GetWorld()->GetTimerManager().SetTimer(...)`를 이용한 시간 제한 퍼즐 기믹 추가.

🔥 2. 랜덤 퍼즐 생성
   - `SpawnActor`를 활용하여 동적으로 발판/이동 플랫폼 배치.
   - `FMath::RandRange`를 이용한 랜덤 속성 (속도, 이동 범위, 각도 등) 부여.
</br>

## 📹 과제 제출 영상
[NBC Assignment 06 Simple Puzzle](https://youtu.be/pK9azRAT-So)
</br>

## 📂 프로젝트 구조
```Text
/Source
    /Simple_Puzzle
        /Actors
            BlinkActor.h / .cpp        // 시간 제한 및 랜덤 속성을 지닌 Actor
            BlinkSpawner.h / .cpp      // SpawnActor
            MovingPlatform.h / .cpp    // 이동하는 플랫폼
            RotatingPlatform.h / .cpp  // 회전하는 발판
        /Simple_Puzzle.Build.cs
/Content
    /Blueprints
        BP_BlinkActor.uasset
        BP_BlinkSpawner.uasset
        BP_MovingPlatform.uasset
        BP_RotatingPlatform.uasset
```
