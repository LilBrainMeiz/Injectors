#include <Windows.h>
#include <iostream>
#include <memory>
#include <string>
#include <functional>
#include "Injection.h"

int main(int argc, char** argv)
{    
    auto oInjectionManager = std::make_unique<Injection>("AssaultCube", "D:\\dlls\\injected.dll");
    oInjectionManager->LoadLibraryInjection();

    std::cin.get();

    return 0;    
}