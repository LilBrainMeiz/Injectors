#include "Memory.h"

t_address Memory::AllocateMemory(t_address address, size_t size)
{
    auto buffer = VirtualAllocEx(this->processHandle,
                     reinterpret_cast<void*>(address), size, MEM_COMMIT,
                     PAGE_READWRITE);

    return buffer;
}