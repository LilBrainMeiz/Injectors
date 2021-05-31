#include <Windows.h>
#include <iostream>
#include <memory>
#include <string>
#include "Memory.h"

int main(int argc, char** argv)
{    
    auto memoryClass = std::make_unique<Memory>("AssaultCube");
   
    t_address local;
    local = memoryClass->ReadMemory<t_address>(0x50F4F4);

    memoryClass->WriteMemory<int>(local + 0x34, std::make_shared<int>(122));

    return 0;    
}