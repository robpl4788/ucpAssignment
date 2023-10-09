#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"

void pushFront(LinkedList* list, void* data)
{
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = list->head;
    list->head = new;
}

void popFront(LinkedList* list, void dataFreer(void*))
{
    Node* newHead = list->head->next;

    dataFreer(list->head->data);
    free(list->head);

    list->head = newHead;
}

void freeList(LinkedList* list, void dataFreer(void*))
{
    Node* nextToFree = list->head;

    while (nextToFree != NULL)
    {
        Node* freeAfter = nextToFree->next;
        dataFreer(nextToFree->data);
        free(nextToFree);

        nextToFree = freeAfter;
    }
}