#include <iostream>
template <typename T, const size_t N> constexpr size_t __countof(T(&)[N]) {
    return N;
}

void swap(int a[], int left, int right) {
    int temp = a[right];
    a[right] = a[left];
    a[left] = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int left = low;

    for (int scanner = low; scanner < high; scanner++) {
        if (a[scanner] < pivot) {
            swap(a, left, scanner);
            left++;
        }
    }
    // Swap the pivot to its correct position
    swap(a, left, high);
    return left;
}

void internal_qsort(int a[], int low, int high) {
    if (low < high) {
        int pivot = partition(a, low, high);
        internal_qsort(a, low, pivot - 1); // Recursively sort left partition
        internal_qsort(a, pivot + 1, high); // Recursively sort right partition
    }
}

void qsort(int a[], int len) {
    internal_qsort(a, 0, len - 1);
}

int main() {
    int a[] = { 33, 77, 1, 8, 0, 3, 5, 1, 79, 33, 9 };
    size_t len = __countof(a);
    qsort(a, len);
    for (auto& i : a)
        std::cout << i << "\n";
}

