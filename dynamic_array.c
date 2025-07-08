#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    size_t count;
    size_t capacity;
} DA;

void da_init(DA *da)
{
   da->capacity = 16;
   da->items = calloc(da->capacity, sizeof(int));
}

void da_push(DA *da, int item)
{
    if (da->count >= da->capacity) {
        da->capacity += da->capacity / 2;
        da->items = reallocarray(da->items, da->capacity, sizeof(int));
    }
    da->items[da->count++] = item;
}

void da_print(DA *da)
{
    printf("DA: [ ");
    for (size_t i = 0; i < da->count; ++i) {
        printf("%d ", da->items[i]);
    }
    printf("] (Capacity = %ld)\n", da->capacity);
}

void da_free(DA *da)
{
   free(da->items);
}

int main(void)
{
    DA da = {0};
    da_init(&da);
    for (size_t i = 0; i < 10; ++i) {
        da_push(&da, i);
    }
    da_print(&da);
    for (size_t i = 0; i < 10; ++i) {
        da_push(&da, i);
    }
    da_print(&da);
    da_free(&da);
    return 0;
}
