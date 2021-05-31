#include <Windows.h>
#include <iostream>
#include <memory>
#include <string>
#include <functional>
#include "Memory.h"

int main(int argc, char** argv)
{    
    auto memoryClass = std::make_unique<Memory>("AssaultCube");
   
    std::string dllPath{"D:\\dlls\\injected.dll"};

    t_address allocationAddy = memoryClass->AllocateMemory(0, sizeof(dllPath.length()));
    PRINT_SUCCESS("Allocation -> " << std::hex << allocationAddy << "\n");

    memoryClass->WriteStringToMemory(allocationAddy, dllPath);

    PTHREAD_START_ROUTINE threatStartRoutineAddress = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32"), "LoadLibraryA");
    CreateRemoteThread(memoryClass->getHandle(), NULL, 0, threatStartRoutineAddress, (void*)allocationAddy, 0, NULL);
    
    std::cin.get();

    return 0;    
}