#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Set {
	size_t size;
	size_t capacity;
	int* data;
};

typedef struct Set Set;

Set create_set() {
	Set result;
	result.size = 0;
	result.capacity = 20;
	result.data = (int*)malloc(result.capacity * sizeof(int));

	return result;
}

bool contains(const Set* const set, int item) {
	for (int i = 0; i < set->size; ++i) {
		if (set->data[i] == item) {
			return true;
		}
	}

	return false;
}

bool add_item(Set* set, int item) {
	if (contains(set, item)) {
		return false;
	}

	if (set->size == set->capacity) {
		set->capacity *= 2;
		set->data = realloc(set->data, set->capacity);
	}
	set->data[set->size++] = item;

	return true;
}

bool remove_item(Set* set, int item) {
	for (int i = 0; i < set->size; ++i) {
		if (set->data[i] == item) {
			set->data[i] = set->data[set->size-1];
			--set->size;
			return true;
		}
	}

	return false;
}

void print_set(const Set* const set) {
	if (set->size == 0) {
		printf("{}\n");
		return;
	}

	printf("{");
	for (int i = 0; i < set->size-1; ++i) {
		printf("%d, ", set->data[i]);
	}
	printf("%d}\n", set->data[set->size-1]);
}

size_t remove_if(Set* set, bool (*predicate)(int)) {
	size_t items_deleted = 0;

	for(int i = 0; i < set->size;) {
		if ((*predicate)(set->data[i])) {
			set->data[i] = set->data[set->size-1];
			--set->size;
			++items_deleted;
		} else {
			++i;
		}
	}

	return items_deleted;
}

bool is_odd(int n) {
	return n % 2 != 0;
}

int main() {
	Set set = create_set();
	add_item(&set, 3);
	add_item(&set, 5);
	add_item(&set, 4);
	add_item(&set, 3);
	add_item(&set, 5);
	add_item(&set, 7);
	add_item(&set, 10);

	print_set(&set);
	remove_item(&set, 3);
	remove_item(&set, 100);

	print_set(&set);

	printf("items deleted: %ld\n", remove_if(&set, &is_odd));
	print_set(&set);

	return 0;
}
