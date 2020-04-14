#include <stdlib.h>

#include "linked_list.h"

void ll_init(LinkedList* l) {
	l->first = NULL;
}

void ll_push_front(LinkedList* l, int elem) {
	Item* new_item = (Item*)malloc(sizeof(Item));
	new_item->value = elem;
	new_item->next = l->first;
	l->first = new_item;
}

void ll_push_back(LinkedList* l, int elem) {
	if (l->first == NULL) {
		ll_push_front(l, elem);
	} else {
		Item* current = l->first;
		while (current->next != NULL) {
			current = current->next;
		}
		Item* new_item = (Item*)malloc(sizeof(Item));
		new_item->value = elem;
		new_item->next = NULL;
		current->next = new_item;
	}
}

void ll_free(LinkedList* l) {
	Item* current = l->first;
	Item* next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
}

int ll_pop_front(LinkedList* l, int* error_code) {
	*error_code = OK;
	if (l->first == NULL) { // list is empty
		// return 0; // we don't know if it's actually first or error
		*error_code = EMPTY_LIST;
		return -1;     // doesn't matter what we return, error code is set
	}

	int return_value = l->first->value;

	Item* temp = l->first->next;
	free(l->first);
	l->first = temp;

	return return_value;
}

void ll_print(const LinkedList* const l) {
	const Item* current = l->first;
	while (current != NULL) {
		printf("%d->", current->value);
		current = current->next;
	}
	printf("NULL\n");
}
