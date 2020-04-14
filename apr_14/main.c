#include <stdio.h>

#include "linked_list.h"
#include "linked_list.h"

int main() {
	int status = OK;

	LinkedList l;
	ll_init(&l);
	//ll_push_front(&l, 5);  // 5->NULL
	//ll_push_front(&l, 4);  // 4->5->NULL
	//ll_push_back(&l, 10);  // 4->5->10->NULL

	ll_print(&l);

	int x = ll_pop_front(&l, &status);
	if (status == OK) {
		printf("popped value: %d\n", x);
		ll_print(&l);
	} else {
		printf("Error, code: %d\n", status);
	}

	ll_free(&l);
}
