/*
Insertion Sort
Input: a sequence of n numbers <a_1, a_2...,a_n>
Output:A permutation (reordering) that a_1'<= a_2'...<= a_n'
We refer to the numbers as "keys", although concepturally we are  sorting a sequence, the input comes to us in the form
of an array with n elements.
Most sorted has the concept of a partition: the sorted partition and the unsorted partition (my note).

Most sorts are to be done in place.

Loop invariant (LI): At the start of each iteration of the for loop of lines "for" to the 
array[i+1] = key, the subarray A[0..j-1] consists of the elements originally in A[0..j-1], but now in sorted order.

Initialization:  LI is true prior to the first iteration of the loop. (for insertion sort, the sorted element is A[0]).
Maintenance:  If it is true before an iteration, it remains true before the next. (for insertion sort, moving A[j-1], 
then A[j-2], ... and so one by one position until it is in the correct sorted position for a[j] saved in key which is
then inserted.)
Termination:  When the loop terminates, the invariant gives us a useful property that helps show that the algorithm
is correct. (when j == len)
 */
#pragma once
// Generic insertion sort template with a comparator
template <typename T, const size_t N, typename Compare = std::greater<T>>
void insertion_sort(T (&array)[N], Compare comp = Compare()) {
    for (size_t j = 1; j < N; ++j) {
        T key = array[j];
        int i = j - 1;
        while (i >= 0 && comp(array[i], key)) {
            array[i + 1] = array[i];
            --i;
        }
        array[i + 1] = key;
    }
}
// Specialization for std::array<char, N>
template <const size_t N>
void insertion_sort(std::array<char, N>& a)
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
