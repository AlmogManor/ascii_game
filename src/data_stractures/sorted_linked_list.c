#include <malloc.h>

#include "sorted_linked_list.h"

typedef SLL_Node Node;

void SLL_add(SortedLinkedList* list, int key, void* value) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;

	if (list->head == NULL) {
		list->head = new_node;
		return;
	}

	if (key < list->head->key) {
		new_node->next = list->head;
		list->head = new_node;
		return;
	}

	Node* before_new; 
	for (before_new = list->head; before_new->next != NULL; before_new = before_new->next) {
		if (before_new->key < key && key <= before_new->next->key) {
			break;
		}
	}

	new_node->next = before_new->next;
	before_new->next=new_node;
}


void* SLL_remove(SortedLinkedList* list, int key) {
	if (list->head == NULL) {
		return NULL;
	}

	if (key == list->head->key) {
		Node* old_head = list->head;
		void* old_head_value = old_head->value;

		list->head = list->head->next;
		
		free(old_head);
		return old_head_value;
	}

	Node* before_delete = NULL; 
	for (before_delete = list->head; before_delete->next != NULL; before_delete = before_delete->next) {
		if (before_delete->next->key == key) {
			break;
		}
	}

	Node* to_delete = before_delete->next;

	if (to_delete == NULL) {
		return NULL;
	}

	before_delete->next = before_delete->next->next;

	void* to_delete_value = to_delete->value;
	free(to_delete);

	return to_delete_value;
}	

void* SLL_get(SortedLinkedList* list, int key) {
	Node* head; 
	for (head = list->head; head != NULL; head = head->next) {
		if (head->key == key) {
			return head->value;
		}
	}
	return NULL;
}

SortedLinkedList* SLL_create() {
	return (SortedLinkedList*)malloc(sizeof(SortedLinkedList));
}

void SLL_destroy(SortedLinkedList* list) {
	free(list);	
}

