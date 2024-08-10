#pragma once
#include "GlobalVariables.h"

class GlobalsManager
{
public:
    GlobalVariables globalVariablesInstance;

    // Static method to access the single instance
    static GlobalsManager* Instance()
    {
        static GlobalsManager instance;
        return &instance;
    }

private:
    // Prevent instantiation
    GlobalsManager() = default;
    GlobalsManager(const GlobalsManager&) = delete;
    GlobalsManager& operator=(const GlobalsManager&) = delete;
};
