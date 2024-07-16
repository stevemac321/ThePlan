/*==============================================================================
 Name        : test.h
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
==============================================================================*/
#pragma once
#define _GNU_SOURCE
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <tuple>
#include <utility>
#include <gtest/gtest.h>

/// Template function to determine the size of a statically allocated array
template <typename T, size_t N>
constexpr size_t _countof(T (&)[N]) {
    return N;
}

/// Template function to print an array
template <typename T, size_t N>
void print_array(T (&a)[N]) {
    for (size_t i = 0; i < _countof(a); i++) {
        printf("%d ", a[i]);
    }
    puts("\n");
}

/// Template function to compare two arrays
template <typename T, size_t N>
bool compare_array(T (&a)[N], T (&cmp)[N]) {
    for (size_t i = 0; i < _countof(a); i++) {
        if (a[i] != cmp[i]) {
            printf("a[%zu] != cmp[%zu] a=%d cmp=%d\n", i, i, a[i], cmp[i]);
            return false;
        }
    }
    return true;
}
