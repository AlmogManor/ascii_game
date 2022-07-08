#include <stdio.h>

#include "data_stractures/sorted_linked_list.h"
/*
void print_key(const char* key[], const char* color) {
	printf(CLEAR_SCREEN);
	printf(color);
	while (*key != 0) {
		printf("%s\n", *key);
		key++;
	}
	printf(RESET_COLOR);
}
*/

void print_linked_list(SortedLinkedList* list) {
	SLL_Node* head;
	for (head = list->head; head != NULL; head = head->next) {
		printf("%s --> ", (char*)head->value);
	}
	printf("null\n");
}

int main(int argc, char** argv) {
	SortedLinkedList* list = SLL_create();
	
	print_linked_list(list);

	SLL_add(list, 5, "hello");
	SLL_add(list, 1, "hi");
	SLL_add(list, 2, "how are you?");
	SLL_add(list, 9, "sup?");

	print_linked_list(list);	

	SLL_remove(list, 2);
	print_linked_list(list);

	SLL_remove(list, 1);
	print_linked_list(list);

	SLL_remove(list, 9);
	print_linked_list(list);

	SLL_remove(list, 5);
	print_linked_list(list);

	SLL_destroy(list);
	return 0;
}
