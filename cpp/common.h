#pragma once
#include <concepts>
#include <type_traits>
#include <memory>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

void enable_virtual_terminal_processing() {
#ifdef _WIN32
    // Get the console handle
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        return;
    }

    // Get the current console mode
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        return;
    }

    // Enable the virtual terminal processing mode
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif
}

template <typename DataType>
concept Numeric = std::is_arithmetic_v<DataType>;

template <typename T, const size_t N> constexpr size_t __countof(T (&)[N]) 
{
    return N;
}

template <typename T, const size_t N> void print_array(T (&a)[N]) 
{
    std::cout << "\n----------Print Array:--------------\n";
    for(auto &i : a) {
        std::cout << i << " ";
    }
    std::cout << "\n--------End Print Array-------------\n\n";
}
template <typename T, const size_t N> bool compare_array(T (&a)[N], T (&b)[N]) 
{
    for(int i=0; i < N; i++) {
        if(a[i] != b[i]) {
            std::cout << RED << "Array a not eq to b at sub " << i << RESET << std::endl;
            print_array(a);
            print_array(b);
            return false;
        }
    }
    std::cout << GREEN << "\nArrays match" << RESET << std::endl;
    return true;
}

