
/*==============================================================================
 Name        : array.cpp 
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
 
==============================================================================*/
#include "test.h"
std::tuple<bool, int, int>  binary_search(const int *a, const int sz, const int find)
{
    if(!a || sz <= 0) {
        perror("bad input");
        return std::make_tuple(false, 0, 0);
    }

    int lo = 0;
    int hi = sz -1;

   while(hi >= lo) { 
       int key = lo + (hi - lo) / 2;
    if(find == a[key]) {
       return std::make_tuple(true, a[key], key);//found, value, at index
    } else if(find < a[key]) {
        hi = key -1;
    }else {
        lo = key +1;
    }
   }

    return std::make_tuple(false, 0, 0);
}
std::pair<int,int> find_peak(const int *a, const int sz)
{
    if(!a || sz <= 0) {
        perror("bad input");
        return std::make_pair(-1, 0);
    }

    int lo = 0;
    int hi = sz - 1;

       while(hi >= lo) {
            int key = lo + (hi - lo) / 2;
            
            // check edge cases 
            if(key == sz -1) {
                if(a[key] >= a[key-1]) {
                    return std::make_pair(a[key], key);
                }
                hi = key - 1;
            } else if (key == 0) {
                if(a[key] >= a[key+1]) {
                    return std::make_pair(a[key], key);
                }
                lo = key +1;
            } // normal, but be peak to the left and right
             else if(a[key] >= a[key-1] && a[key] >= a[key+1]) {
                    return std::make_pair(a[key], key);
            }
            else if(a[key] < a[key -1]) {
                hi = key -1;
            }
            else {
                lo = key + 1;
            }
       }
       return std::make_pair(-1, 0);  // should never get here really
}
int smallest_subarray(const int a[], const int len, const int x) {
    if (len <= 0) {
        return 0;
    }

    int left = 0;
    int right = 0;
    int curmax = 0;
    int curlenmax = len + 1;  // Set to an initial value larger than any possible subarray length

    while (right < len) {
        // Expand the window
        while (curmax <= x && right < len) {
            curmax += a[right];
            right++;
        }

        // Shrink the window
        while (curmax > x && left < len) {
            curlenmax = std::min(curlenmax, right - left);
            curmax -= a[left];
            left++;
        }
    }

    // If no subarray was found, return 0
    return (curlenmax == len + 1) ? 0 : curlenmax;
}

std::pair<int, int> left_and_rightmost_indexes(const int a[], const int x, const int len)
{
    if(len <= 0) {
        puts("bad input");
        return std::make_pair(-1,-1);
    }

    int left = 0;
    int right = 0;
    while(left < len && a[left] != x) {
        left++;
    }
    if(left == len) {
        return std::make_pair(-1,-1);
    }

    right = left;

    while(right+1 < len && a[right+1] == x) {
        right++;
    }

    return std::make_pair(left, right);
}
int get_common_prefix(const char* left, const char* right)
{
    assert(left && right);
    const char* pl = left;
    const char* pr = right;
    while (*pl != '\0' && *pr != '\0' && *pl == *pr) {
        ++pl;
        ++pr;
    }
    if (*pl == '\0' && *pr == '\0') {
        return -1;
    }

    return pl - left;
}
template <typename T, size_t N>
std::string longest_common_prefix(T* (&a)[N])
{
    std::string result;

    if (N <= 0) {
        result = "-1";
        return result;
    }

    int longest = get_common_prefix(a[0], a[1]);
    for (size_t col = 2; col < N; col++) {
        int ret = get_common_prefix(a[col - 1], a[col]);
        if (ret == -1) {
            result = "-1";
            return result;
        }
        if (ret < longest) {
            longest = ret;
        }
    }
    if (longest == -1) {
        result = "-1";
        return result;
    }

    for (int i = 0; i < longest; i++) {
        result += a[0][i];
    }
    return result;
}
