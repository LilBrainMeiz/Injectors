#pragma once
#include "Memory.h"

class Injection
{
private:
    std::unique_ptr<Memory> oMemClass;

    std::string sDllPath; // For LoadLibrary;

public:
    Injection(std::string sProcess, std::string sDllPath)
    {
        this->oMemClass = std::make_unique<Memory>(sProcess.c_str());
        this->sDllPath  = sDllPath;
    }
    
    auto LoadLibraryInjection() -> void;
};

