#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BlueprintRotationLibrary.generated.h"

UCLASS()
class BLUEPRINTQUATERNIONLIBRARY_API UBlueprintRotationLibrary : public UObject
{
    GENERATED_BODY()

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Lerp (Quat)"))
    static FQuat Lerp(const FQuat& A, const FQuat& B, const float& Alpha);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Fast Lerp (Quat)"))
    static FQuat FastLerp(const FQuat& A, const FQuat& B, const float& Alpha);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="BiLerp (Quat)"))
    static FQuat BiLerp(
            const FQuat& P00,
            const FQuat& P10,
            const FQuat& P01,
            const FQuat& P11,
            const float& FracX,
            const float& FracY
            );

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Fast BiLerp (Quat)"))
    static FQuat FastBiLerp(
            const FQuat& P00,
            const FQuat& P10,
            const FQuat& P01,
            const FQuat& P11,
            const float& FracX,
            const float& FracY
            );

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Slerp (Quat)"))
    static FQuat Slerp(const FQuat& A, const FQuat& B, const float& Slerp);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Slerp (Not Normalized) (Quat)"))
    static FQuat Slerp_NotNormalized(const FQuat& A, const FQuat& B, const float& Slerp);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Dot (Quat)", CompactNodeTitle="dot"))
    static float Dot(const FQuat& A, const FQuat& B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FQuat VectorToOrientationQuat(const FVector Vector);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(BlueprintAutocast))
    static FRotator VectorToOrientationRotator(const FVector Vector);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FQuat RotatorToQuat(const FRotator Rotator);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(BlueprintAutocast))
    static FRotator QuatToRotator(const FQuat& Quat);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static float AngleBetweenDirectionVectorsRad(FVector A, FVector B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static float AngleBetweenDirectionVectorsDeg(FVector A, FVector B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static float AngleBetweenQuatsRad(FQuat A, FQuat B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static float AngleBetweenQuatsDeg(FQuat A, FQuat B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FQuat EulerDegToQuat(const FVector Euler);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FVector QuatToEulerDeg(const FQuat& Quat);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Quat + Quat", CompactNodeTitle="+"))
    static FQuat QuatPlusQuat(const FQuat& A, const FQuat& B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Quat - Quat", CompactNodeTitle="-"))
    static FQuat QuatMinusQuat(const FQuat& A, const FQuat& B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Quat * Quat", CompactNodeTitle="*"))
    static FQuat QuatMultiplyQuat(const FQuat& A, const FQuat& B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Quat * Float (Scale)", CompactNodeTitle="* (Scale)"))
    static FQuat QuatMultiplyFloatScale(const FQuat& A, const float B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Quat / Float (Scale)", CompactNodeTitle="/ (Scale)"))
    static FQuat QuatDivFloatScale(const FQuat& A, const float B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(DisplayName="Quat == Quat", CompactNodeTitle="=="))
    static bool AreQuatsEqual(const FQuat& A, const FQuat& B);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary", meta=(BlueprintAutocast))
    static FString QuatToString(const FQuat& Quat);

    UFUNCTION(BlueprintCallable, Category="BlueprintRotationLibrary")
    static void AddActorLocalRotation(AActor* Actor, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport);

    UFUNCTION(BlueprintCallable, Category="BlueprintRotationLibrary")
    static void AddActorWorldRotation(AActor* Actor, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport);

    UFUNCTION(BlueprintCallable, Category="BlueprintRotationLibrary")
    static void AddComponentLocalRotation(USceneComponent* Component, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport);

    UFUNCTION(BlueprintCallable, Category="BlueprintRotationLibrary")
    static void AddComponentRelativeRotation(USceneComponent* Component, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport);

    UFUNCTION(BlueprintCallable, Category="BlueprintRotationLibrary")
    static void AddComponentWorldRotation(USceneComponent* Component, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport);

    UFUNCTION(BlueprintCallable, Category="BlueprintRotationLibrary")
    static void SetActorRelativeRotation(AActor* Actor, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport);

    UFUNCTION(BlueprintCallable, Category="BlueprintRotationLibrary")
    static void SetActorRotation(AActor* Actor, const FQuat& Quat, bool bTeleport);

    UFUNCTION(BlueprintCallable, Category="BlueprintRotationLibrary")
    static void SetComponentRelativeRotation(USceneComponent* Component, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport);

    UFUNCTION(BlueprintCallable, Category="BlueprintRotationLibrary")
    static void SetComponentWorldRotation(USceneComponent* Component, const FQuat& Quat, bool bSweep, FHitResult& OutSweepHitResult, bool bTeleport);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FQuat GetTransformQuat(const FTransform Transform);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static void BreakTransformQuat(const FTransform Transform, FVector& Location, FQuat& RotationQuat, FVector& Scale);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static void QuatAxisAngleRad(const FQuat& Quat, float& OutAngleRad, FVector& OutAxis);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static void QuatAxisAngleDeg(const FQuat& Quat, float& OutAngleDeg, FVector& OutAxis);

    /**
     * @brief Generates the 'smallest' (geodesic) rotation between two normals (assumed to be unit length).
     *
     * Copied from C++ docs
     */
    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FQuat FindBetweenNormals(const FVector& Normal1, const FVector& Normal2);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FVector GetForwardVector(const FQuat& Quat);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FVector GetRightVector(const FQuat& Quat);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FVector GetUpVector(const FQuat& Quat);

    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FQuat Inverse(const FQuat& Quat);

    /**
     * @brief Convert a rotation into a unit vector facing in its direction.
     *
     * Copied from C++ docs
     */
    UFUNCTION(BlueprintPure, Category="BlueprintRotationLibrary")
    static FVector QuatToVector(const FQuat& Quat);
};
