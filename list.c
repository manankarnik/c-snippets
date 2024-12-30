#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t element_size;
} List;

List* list_create(size_t initial_capacity, size_t element_size)
{
    List *list = malloc(sizeof(List));
    list->data = malloc(initial_capacity*element_size);
    list->size = 0;
    list->capacity = initial_capacity;
    list->element_size = element_size;
    return list;
}

void *list_get(List *list, size_t index)
{
    return (char*)list->data + index * list->element_size;
}

void list_push(List *list, void *value)
{
    if (list->size == list->capacity) {
        list->capacity++;
        list->data = realloc(list->data, (list->size + 1) * list->element_size);
    }
    void *target = list_get(list, list->size);
    memcpy(target, value, list->element_size);
    list->size++;
}

int main(void)
{
    List *list = list_create(2, sizeof(int));
    for (size_t i = 0; i < 10; ++i) {
        list_push(list, &i);
    }
     printf("Items: ");
    for (size_t i = 0; i < list->size; ++i) {
        printf("%d ", *(int*)list_get(list, i));
    }
    printf("\n");
    for (size_t i = 10; i < 20; ++i) {
        list_push(list, &i);
    }
    printf("Items: ");
    for (size_t i = 0; i < list->size; ++i) {
        printf("%d ", *(int*)list_get(list, i));
    }
    printf("\n");
    return 0;
}
