#pragma once
#include <iostream>

#define PRINT_SUCCESS( ... ) std::cout << "[+] " __VA_ARGS__;
#define PRINT_ERROR( ... ) std::cout << "[-] " __VA_ARGS__;

typedef long long t_address;