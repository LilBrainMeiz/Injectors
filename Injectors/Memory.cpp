#include "Memory.h"

t_address Memory::AllocateMemory(t_address address, size_t size)
{
    void* allocation = VirtualAllocEx(this->processHandle, reinterpret_cast<void*>(address),
                           size, MEM_COMMIT, PAGE_READWRITE);

    t_address allocationAddress = reinterpret_cast<t_address>(allocation);

    return allocationAddress;
}