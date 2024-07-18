#pragma once
#ifdef _WIN32
#include <windows.h>
#endif

const char * RESET = "\033[0m";
const char * RED = "\033[31m";
const char * GREEN = "\033[32m";

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

/* TEST HARNESS*/

extern int passed;
extern int failed;
extern int tcs;

#define TC_BEGIN(func) \
    printf("--------------------TESTCASE BEGIN %s ---------------------\n", func); \
    tcs++;

#define VERIFY(x) \
    if (x) { \
        printf("%s", GREEN); \
        passed++; \
    } else { \
        printf("%s", RED); \
        failed++; \
    } \
    printf("%s", RESET); \
    assert(x)

#define PASSED(func, line) \
    printf("%s--------------------PASSED %s Line: %d --------------------%s\n", GREEN, func, line, RESET); \
    passed++;

#define REPORT(msg) \
    printf("--%s TESTCASES: %d TESTS PASSED: %d TESTS FAILED: %d-------\n", msg, tcs, passed, failed);
