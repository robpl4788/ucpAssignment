#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

void pushFront(LinkedList* list, void* data);
void popFront(LinkedList* list, void dataFreer(void* data));
void freeList(LinkedList* list, void dataFreer(void* data));



#endif