#include <stdio.h>
#include <assert.h>

int zeros2end(int a[], int len) {
    int new_len = 0; // This will track the new length of the array without zeros

    // First, move all non-zero elements to the front
    for (int i = 0; i < len; i++) {
        if (a[i] != 0) {
            a[new_len] = a[i];
            new_len++;
        }
    }

    // Fill the remaining elements with zero
    for (int i = new_len; i < len; i++) {
        a[i] = 0;
    }

    return new_len;
}

int main() {
    {
        int a[] = { 1, 4, 7, 0, 3, 8 };
        int len = sizeof(a) / sizeof(a[0]);
        int newlen = zeros2end(a, len);
        assert(newlen == 5);
        for (int i = 0; i < len; i++) {  // Show old length to make sure zeros are there
            printf("%d\n", a[i]);
        }
        puts("----------------------------------------------\n");
    }
    {
        int a2[] = { 1, 4, 7, 0, 3, 0 };
        int len = sizeof(a2) / sizeof(a2[0]);
        int newlen = zeros2end(a2, len);
        assert(newlen == 4);
        for (int i = 0; i < len; i++) {  // Show old length to make sure zeros are there
            printf("%d\n", a2[i]);
        }
        puts("----------------------------------------------\n");
    }
    {
        int a3[] = { 1, 4, 7, 0, 3, 0, 88, 99, 11, 0, 0, 0, 14, 88, 3, 0, 8, 9, 1, 1, 0 };
        int len = sizeof(a3) / sizeof(a3[0]);
        int newlen = zeros2end(a3, len);
        assert(newlen == 14); // Assuming the correct new length is 14
        for (int i = 0; i < len; i++) {  // Show old length to make sure zeros are there
            printf("%d\n", a3[i]);
        }
        puts("----------------------------------------------\n");
    }
    return 0;
}
