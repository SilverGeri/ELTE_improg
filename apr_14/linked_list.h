#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

struct Item {
	int value;
	struct Item* next;
};
typedef struct Item Item;

struct LinkedList {
	Item* first;
};

typedef struct LinkedList LinkedList;

enum Errors { OK, EMPTY_LIST };

void ll_init(LinkedList* l);
void ll_push_front(LinkedList* l, int elem);
void ll_push_back(LinkedList* l, int elem);
void ll_free(LinkedList* l);

int ll_pop_front(LinkedList* l, int* error_code);
int ll_pop_back(LinkedList*l, int* error_code); // homework, pops last element, similarly to pop_front
int ll_empty(const LinkedList* const l);        // homework, returns 1 if list is empty, 0 otherwise
int ll_front(const LinkedList* const l, int* error_code); // homework, returns first element if list is not empty
int ll_back(const LinkedList* const l, int* error_code); // homework, returns last element if list is not empty

LinkedList ll_clone(const LinkedList* const l); // copy the whole linkedlist without aliasing

void ll_print(const LinkedList* const l);

#endif

