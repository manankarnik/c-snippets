#include <stdio.h>
#include <stdlib.h>

#define HEAP_CAPACITY 100000

typedef struct {
    int     *items;
    size_t  size;
    bool    is_min;
} Heap;

void heap_init(Heap *heap, bool is_min)
{
    heap->items = calloc(HEAP_CAPACITY, sizeof(int));
    heap->size = 0;
    heap->is_min = is_min;
}

void heap_push(Heap *heap, int x)
{
    heap->items[heap->size++] = x;
    int i = heap->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if ((heap->items[parent] > heap->items[i]) ^ heap->is_min) break;
        int tmp = heap->items[parent];
        heap->items[parent] = heap->items[i];
        heap->items[i] = tmp;
        i = parent;
    }
}

void heap_heapify(Heap *heap, int *arr, size_t arr_size)
{
    for (size_t i = 0; i < arr_size; ++i) heap_push(heap, arr[i]);
}

int heap_pop(Heap *heap)
{
    int top = heap->items[0];
    heap->items[0] = heap->items[--heap->size];
    size_t i = 0;
    while (2 * i + 1 < heap->size) {
        size_t key   = i;
        size_t left  = 2 * i + 1;
        size_t right = 2 * i + 2;
        if ((heap->items[left]  > heap->items[key]) ^ heap->is_min) key = left;
        if ((heap->items[right] > heap->items[key]) ^ heap->is_min) key = right;
        if (key == i) break;
        int tmp = heap->items[i];
        heap->items[i] = heap->items[key];
        heap->items[key] = tmp;
        i = key;
    }
    return top;
}

void heap_free(Heap heap)
{
    free(heap.items);
}

void heap_print(Heap heap)
{ 
    printf("Heap: [");
    for (size_t i = 0; i < heap.size; ++i) {
        printf("%d", heap.items[i]);
        if (i != heap.size - 1) printf(", ");
    }
    printf("]\n");
}

int main(void)
{
    int arr[] = {10, 20, -5, 15, 5, 25, -10, 30};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    Heap heap = {0};
    heap_init(&heap, false);
    heap_heapify(&heap, arr, arr_size);
    heap_push(&heap, 40);
    heap_print(heap);
    heap_push(&heap, 35);
    heap_print(heap);

    size_t size = heap.size;
    for (size_t i = 0; i < size; ++i) {
        printf("Popped %d\n", heap_pop(&heap));
        heap_print(heap);
    }

    heap_free(heap);
    return 0;
}
