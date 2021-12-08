#include "BlueprintRotationLibrary.h"

FQuat UBlueprintRotationLibrary::Lerp(const FQuat& A, const FQuat& B, const float& Alpha)
{
    return FMath::Lerp(A, B, Alpha);
}

FQuat UBlueprintRotationLibrary::FastLerp(const FQuat& A, const FQuat& B, const float& Alpha)
{
    return FQuat::FastLerp(A, B, Alpha);
}

FQuat UBlueprintRotationLibrary::BiLerp(const FQuat& P00, const FQuat& P10, const FQuat& P01, const FQuat& P11, const float& FracX, const float& FracY)
{
    return FMath::BiLerp(P00, P10, P01, P11, FracX, FracY);
}

FQuat UBlueprintRotationLibrary::FastBiLerp(const FQuat& P00, const FQuat& P10, const FQuat& P01, const FQuat& P11, const float& FracX, const float& FracY)
{
    return FQuat::FastBilerp(P00, P10, P01, P11, FracX, FracY);
}

FQuat UBlueprintRotationLibrary::Slerp(const FQuat& A, const FQuat& B, const float& Slerp)
{
    return FQuat::Slerp(A, B, Slerp);
}

FQuat UBlueprintRotationLibrary::Slerp_NotNormalized(const FQuat& A, const FQuat& B, const float& Slerp)
{
    return FQuat::Slerp_NotNormalized(A, B, Slerp);
}

float UBlueprintRotationLibrary::Dot(const FQuat& A, const FQuat& B)
{
    return A | B;
}

FQuat UBlueprintRotationLibrary::VectorToOrientationQuat(const FVector Vector)
{
    return Vector.ToOrientationQuat();
}

FRotator UBlueprintRotationLibrary::VectorToOrientationRotator(const FVector Vector)
{
    return Vector.ToOrientationRotator();
}

FQuat UBlueprintRotationLibrary::RotatorToQuat(const FRotator Rotator)
{
    return Rotator.Quaternion();
}

FRotator UBlueprintRotationLibrary::QuatToRotator(const FQuat& Quat)
{
    return FRotator(Quat);
}

float UBlueprintRotationLibrary::AngleBetweenDirectionVectorsRad(FVector A, FVector B)
{
    A.Normalize(1.0f);
    B.Normalize(1.0f);

    return FGenericPlatformMath::Acos(FVector::DotProduct(A, B));
}

float UBlueprintRotationLibrary::AngleBetweenDirectionVectorsDeg(FVector A, FVector B)
{
    A.Normalize(1.0f);
    B.Normalize(1.0f);

    return FMath::RadiansToDegrees(FGenericPlatformMath::Acos(FVector::DotProduct(A, B)));
}

float UBlueprintRotationLibrary::AngleBetweenQuatsRad(FQuat A, FQuat B)
{
    return A.AngularDistance(B);
}

float UBlueprintRotationLibrary::AngleBetweenQuatsDeg(FQuat A, FQuat B)
{
    return FMath::RadiansToDegrees(A.AngularDistance(B));
}

FQuat UBlueprintRotationLibrary::EulerDegToQuat(const FVector Euler)
{
    return FQuat::MakeFromEuler(Euler);
}

FVector UBlueprintRotationLibrary::QuatToEulerDeg(const FQuat& Quat)
{
    return Quat.Euler();
}

FQuat UBlueprintRotationLibrary::QuatPlusQuat(const FQuat& A, const FQuat& B)
{
    return A + B;
}

FQuat UBlueprintRotationLibrary::QuatMinusQuat(const FQuat& A, const FQuat& B)
{
    return A - B;
}

FQuat UBlueprintRotationLibrary::QuatMultiplyQuat(const FQuat& A, const FQuat& B)
{
    return A * B;
}

FQuat UBlueprintRotationLibrary::QuatMultiplyFloatScale(const FQuat& A, const float B)
{
    return A * B;
}

FQuat UBlueprintRotationLibrary::QuatDivFloatScale(const FQuat& A, const float B)
{
    return A / B;
}

bool UBlueprintRotationLibrary::AreQuatsEqual(const FQuat& A, const FQuat& B)
{
    return A == B;
}

FString UBlueprintRotationLibrary::QuatToString(const FQuat& Quat)
{
    return FString::Printf(TEXT("X=%f,Y=%f,Z=%f,W=%f"), Quat.X, Quat.Y, Quat.Z, Quat.W);
}

void UBlueprintRotationLibrary::AddActorLocalRotation(AActor* Actor, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport)
{
    ETeleportType Teleport;

    if (bTeleport)
    {
        Teleport = ETeleportType::TeleportPhysics;
    }
    else
    {
        Teleport = ETeleportType::None;
    }

    Actor->AddActorLocalRotation(Quat, bSweep, &OutSweepHitResult, Teleport);
}

void UBlueprintRotationLibrary::AddActorWorldRotation(AActor* Actor, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport)
{
    ETeleportType Teleport;

    if (bTeleport)
    {
        Teleport = ETeleportType::TeleportPhysics;
    }
    else
    {
        Teleport = ETeleportType::None;
    }

    Actor->AddActorWorldRotation(Quat, bSweep, &OutSweepHitResult, Teleport);
}

void UBlueprintRotationLibrary::AddComponentLocalRotation(USceneComponent* Component, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport)
{
    ETeleportType Teleport;

    if (bTeleport)
    {
        Teleport = ETeleportType::TeleportPhysics;
    }
    else
    {
        Teleport = ETeleportType::None;
    }

    Component->AddLocalRotation(Quat, bSweep, &OutSweepHitResult, Teleport);
}

void UBlueprintRotationLibrary::AddComponentRelativeRotation(USceneComponent* Component, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport)
{
    ETeleportType Teleport;

    if (bTeleport)
    {
        Teleport = ETeleportType::TeleportPhysics;
    }
    else
    {
        Teleport = ETeleportType::None;
    }

    Component->AddRelativeRotation(Quat, bSweep, &OutSweepHitResult, Teleport);
}

void UBlueprintRotationLibrary::AddComponentWorldRotation(USceneComponent* Component, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport)
{
    ETeleportType Teleport;

    if (bTeleport)
    {
        Teleport = ETeleportType::TeleportPhysics;
    }
    else
    {
        Teleport = ETeleportType::None;
    }

    Component->AddWorldRotation(Quat, bSweep, &OutSweepHitResult, Teleport);
}

void UBlueprintRotationLibrary::SetActorRelativeRotation(AActor* Actor, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport)
{
    ETeleportType Teleport;

    if (bTeleport)
    {
        Teleport = ETeleportType::TeleportPhysics;
    }
    else
    {
        Teleport = ETeleportType::None;
    }

    Actor->SetActorRelativeRotation(Quat, bSweep, &OutSweepHitResult, Teleport);
}

void UBlueprintRotationLibrary::SetActorRotation(AActor* Actor, const FQuat& Quat, bool bTeleport)
{
    ETeleportType Teleport;

    if (bTeleport)
    {
        Teleport = ETeleportType::TeleportPhysics;
    }
    else
    {
        Teleport = ETeleportType::None;
    }

    Actor->SetActorRotation(Quat, Teleport);
}

void UBlueprintRotationLibrary::SetComponentRelativeRotation(USceneComponent* Component, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport)
{
    ETeleportType Teleport;

    if (bTeleport)
    {
        Teleport = ETeleportType::TeleportPhysics;
    }
    else
    {
        Teleport = ETeleportType::None;
    }

    Component->SetRelativeRotation(Quat, bSweep, &OutSweepHitResult, Teleport);
}

void UBlueprintRotationLibrary::SetComponentWorldRotation(USceneComponent* Component, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport)
{
    ETeleportType Teleport;

    if (bTeleport)
    {
        Teleport = ETeleportType::TeleportPhysics;
    }
    else
    {
        Teleport = ETeleportType::None;
    }

    Component->SetWorldRotation(Quat, bSweep, &OutSweepHitResult, Teleport);
}

FQuat UBlueprintRotationLibrary::GetTransformQuat(const FTransform Transform)
{
    return Transform.GetRotation();
}

void UBlueprintRotationLibrary::BreakTransformQuat(const FTransform Transform, FVector& Location, FQuat& RotationQuat, FVector& Scale)
{
    Location = Transform.GetLocation();
    RotationQuat = Transform.GetRotation();
    Scale = Transform.GetScale3D();
}

void UBlueprintRotationLibrary::QuatAxisAngleRad(const FQuat& Quat, float& OutAngleRad, FVector& OutAxis)
{
    OutAngleRad = Quat.GetAngle();
    OutAxis = Quat.GetRotationAxis();
}

void UBlueprintRotationLibrary::QuatAxisAngleDeg(const FQuat& Quat, float& OutAngleDeg, FVector& OutAxis)
{
    OutAngleDeg = FMath::RadiansToDegrees(Quat.GetAngle());
    OutAxis = Quat.GetRotationAxis();
}

FQuat UBlueprintRotationLibrary::FindBetweenNormals(const FVector& Normal1, const FVector& Normal2)
{
    return FQuat::FindBetweenNormals(Normal1, Normal2);
}

FVector UBlueprintRotationLibrary::GetForwardVector(const FQuat& Quat)
{
    return Quat.GetForwardVector();
}

FVector UBlueprintRotationLibrary::GetRightVector(const FQuat& Quat)
{
    return Quat.GetRightVector();
}

FVector UBlueprintRotationLibrary::GetUpVector(const FQuat& Quat)
{
    return Quat.GetUpVector();
}

FQuat UBlueprintRotationLibrary::Inverse(const FQuat& Quat)
{
    return Quat.Inverse();
}

FVector UBlueprintRotationLibrary::QuatToVector(const FQuat& Quat)
{
    return Quat.Vector();
}
