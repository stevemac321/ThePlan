/*
Insertion Sort
Input: a sequence of n numbers <a_1, a_2...,a_n>
Output:A permutation (reordering) that a_1'<= a_2'...<= a_n'
We refer to the numbers as "keys", although concepturally we are  sorting a sequence, the input comes to us in the form
of an array with n elements.
Most sorted has the concept of a partition: the sorted partition and the unsorted partition (my note).

Most sorts are to be done in place.

Loop invariant properties:

 */
#pragma once
#include <concepts>
#include <type_traits>

template <Numeric DataType, const size_t N> void insertion_sort(DataType (&a)[N]) 
{
    for(int j = 1; j < N; j++) {
        int key = a[j]; //save this until correct place in sorted array is found.
        // insert a[j] into sorted sequence A[0..j-1] (keep in mind we are zero based however)
        int i = j - 1;
        while(i >= 0 && a[i] > key) {
            a[i+1] =a[i];
            i--;
        }
        a[i+1] = key;
    }
}
// add string by lexical order specialization