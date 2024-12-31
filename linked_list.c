#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int  data;
    void *next;
} Node;

typedef struct {
    Node   *head;
    size_t size;
} LinkedList;

LinkedList* list_create()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void list_push(LinkedList *list, int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head) {
        Node *last = list->head;
        while (last->next) {
            last = last->next;
        }
        last->next = node;
    } else {
        list->head = node;
    }
    list->size++;
}

void list_insert(LinkedList *list, int data, size_t index)
{
    Node *target = list->head;
    Node *node = malloc(sizeof(Node));
    node->data = data;
    if (index == 0) {
        list->head = node;
        node->next = target;
    } else {
        for (size_t i = 0; i < (index - 1); ++i) {
            target = target->next;
        }
        node->next = target->next;
        target->next = node;
    }
    list->size++;
}

void list_remove(LinkedList *list, size_t index)
{
    Node *target = list->head;
    if (index == 0) {
        list->head = target->next;
    } else {
        Node *prev = target;
        for (size_t i = 0; i < (index - 1); ++i) {
            target = target->next;
            prev = prev->next;
        }
        target = prev->next;
        prev->next = target->next;
    }
    free(target);
    list->size--;
}

int list_get(LinkedList *list, size_t index)
{
    Node *node = list->head;
    for (size_t i = 0; i < index; ++i) {
        node = node->next;
    }
    return node->data;
}

void list_print(LinkedList *list)
{
    printf("Linked List: ");
    for (size_t i = 0; i < list->size; ++i) {
        printf("%d ", list_get(list, i));
    }
    printf("\n");
}

void list_free(LinkedList *list)
{
    Node *target = list->head;
    while (target) {
        Node *next = target->next;
        free(target);
        target = next;
    }
    free(list);
}

int main(void)
{
    LinkedList *list = list_create();
    for (size_t i = 0; i < 10; ++i) {
        list_push(list, i);
    }
    list_print(list);
    for (size_t i = 0; i < 10; ++i) {
        list_insert(list, 100, i);
    }
    list_print(list);
    for (size_t i = 0; i < 10; ++i) {
        list_remove(list, 0);
    }
    list_print(list);
    list_free(list);
    return 0;
}
