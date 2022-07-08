#ifndef SORTED_LINKED_LIST
#define SORTED_LINKED_LIST

// this list is sorted such that the first item has the smallest key

typedef struct SLL_Node SLL_Node;

struct SLL_Node {
	int key;
	void* value;

	SLL_Node* next;
};


typedef struct SortedLinkedList {
	SLL_Node* head;
} SortedLinkedList;

void SLL_add(SortedLinkedList* list, int key, void* value);
// returns the value removed
void* SLL_remove(SortedLinkedList* list, int key);
void* SLL_get(SortedLinkedList* list, int key);

SortedLinkedList* SLL_create();
// this assumes that the list is empty (otherwise you may not be able to free all of the values)
void SLL_destroy(SortedLinkedList* list);

#endif
