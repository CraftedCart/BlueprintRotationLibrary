#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FBlueprintQuaternionLibraryModule : public IModuleInterface
{
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};