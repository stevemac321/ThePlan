/*
  Finding Maximum and Minimum:
• Write functions to find the maximum and minimum values in an array. 
• Consider edge cases (empty array, repeated values). 
 */
#include <stdio.h>
#include <stdbool.h>

#define _countof(x) sizeof(x) / sizeof(x[0])

struct pair {
    bool valid;
    int min;
    int max;
};

struct pair max_min(const int a[], const int len)
{
    struct pair ret = {.valid=false,.min=0, .max=0};
    if(len <= 0) {
        puts("bad input");
        return ret;
    } else {
        ret.valid = true;
        ret.min = a[0];
        ret.max = a[0];
    }

    for(int i=1; i<len; i++) {
        if(a[i] < ret.min) {
            ret.min = a[i];
        }
        if(a[i] > ret.max) {
            ret.max = a[i];
        }
    }

    return ret;
}

void test_max_min()
{
    int array[] = {3, 5, 1, 8, 2, 7, 6};
    int len = _countof(array);

    struct pair result = max_min(array, len);
    if (result.valid) {
        printf("Minimum: %d\n", result.min);
        printf("Maximum: %d\n", result.max);
    } else {
        printf("Invalid input.\n");
    }
}

int main()
{
    test_max_min();
}
