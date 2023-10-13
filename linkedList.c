#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"

/* Insert a new item at the front of a linked list */
void pushFront(LinkedList* list, void* data)
{
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = list->head;
    list->head = new;
}

/* Deletes the first element of a linked list
- dataFreer is called on the data pointer stored by the node */
void popFront(LinkedList* list, void dataFreer(void*))
{
    Node* newHead = list->head->next;

    dataFreer(list->head->data);
    free(list->head);

    list->head = newHead;
}

/* Delets all elements of a linked list
- dataFreer is called on the data pointer stored by the node */
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