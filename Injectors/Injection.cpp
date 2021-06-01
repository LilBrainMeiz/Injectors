#include "Injection.h"

void Injection::LoadLibraryInjection()
{
    auto sPath = this->sDllPath.c_str();
    auto iLength = this->sDllPath.length();

    t_address llAllocation = this->oMemClass->AllocateMemory(0, iLength);
    oMemClass->WriteStringToMemory(llAllocation, sPath);

    PTHREAD_START_ROUTINE threatStartRoutineAddress = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32"), "LoadLibraryA");
    CreateRemoteThread(oMemClass->getHandle(), NULL, 0, threatStartRoutineAddress, (void*)llAllocation, 0, NULL);

    PRINT_SUCCESS("Injected -> " << sPath << " at " << llAllocation << " of size " << iLength);
}