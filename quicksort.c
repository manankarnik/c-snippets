#include <stdio.h>

void print_array(int* arr, int len) {
    printf("[ ");
    for (long i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int *arr, int low, int high)
{
    if (low >= high) return;
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    quicksort(arr, 0, i - 1);
    quicksort(arr, i + 1, high);
}

int main(void) {
    int arr[] = {14, 2, 34, 645, 22, 38, 63, 11};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Array:  ");
    print_array(arr, len);
    quicksort(arr, 0, len - 1);
    printf("Sorted: ");
    print_array(arr, len);
    return 0;
}
