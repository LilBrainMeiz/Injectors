#pragma once
#include <Windows.h>
#include <memory>
#include <string>
#include "Helper.h"

class Memory
{
private:
    std::string processWindowName; 
    HANDLE      processHandle;

public:
    Memory(std::string processWindowName)
    {
        HWND  processHandleToWindow;
        std::unique_ptr<DWORD> processId = std::make_unique<DWORD>();

        this->processWindowName = processWindowName;
        
        processHandleToWindow = FindWindowA(0,
                                this->processWindowName.c_str());

        GetWindowThreadProcessId(processHandleToWindow, processId.get());
        this->processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, *processId);
    
        if (this->processHandle == nullptr)
        {
            PRINT_ERROR("processHandle was nullptr\n");
            PRINT_ERROR("Error code -> " << GetLastError() << "\n");
        }
        else
        {
            PRINT_SUCCESS("processHandle was found\n");
        }
    }
    
    template <typename _Ty>
    inline void WriteMemory(t_address address, std::shared_ptr<_Ty> buffer)
    {
        if (buffer == nullptr)
        {
            PRINT_ERROR("Write buffer was null\n");
            return;
        }

        PRINT_SUCCESS("Write buffer : " << *buffer << "\n");

        

        WriteProcessMemory(this->processHandle, reinterpret_cast<void*>(address),
            buffer.get(), sizeof(_Ty), nullptr);
    }

    inline void WriteStringToMemory(t_address address, std::string str)
    {
        auto string = str.c_str();
        auto length = str.length();

        PRINT_SUCCESS("String to write : " << string << "\n");

        WriteProcessMemory(this->processHandle, reinterpret_cast<void*>(address),
                           string, length, nullptr);
    }

    template <typename _Ty>
    inline _Ty ReadMemory(t_address address)
    {
        auto buffer = std::make_shared<_Ty>();

        ReadProcessMemory(this->processHandle, reinterpret_cast<void*>(address),
           buffer.get(), sizeof(_Ty), nullptr);

        if (buffer == nullptr)
        {
            PRINT_ERROR("Read buffer was null\n");
            return 0;
        }

        PRINT_SUCCESS("Read buffer : " << *buffer << "\n");

        return *buffer;
    }

    t_address AllocateMemory(t_address address, size_t size);

    inline HANDLE getHandle(){ return this->processHandle; }
};

