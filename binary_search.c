#include <stdio.h>

int binary_search(int *arr, size_t arr_size, int x)
{
    size_t left = 0;
    size_t right = arr_size - 1;
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 10, 21, 54, 66};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < arr_size; ++i) {
        printf("Found %d at index: %d\n", arr[i], binary_search(arr, arr_size, arr[i]));
    }
    return 0;
}
