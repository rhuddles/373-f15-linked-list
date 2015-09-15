#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	list_t* current = head;
	list_t* last_el = NULL;

	while(new_element->index > current->index){
		last_el=current;
		current=current->next;
		if(current->next == NULL)
			break;
	}

	if(current->next != NULL)
		new_element->next = current;
	else if(new_element->index > current->index){
		current->next = new_element;
		new_element->next=NULL;
		last_el=current;
	}
	else {
		last_el->next=new_element;
		new_element->next=current;
	}


	if(last_el != NULL)
		last_el->next = new_element;
	else
		head = new_element;

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);


	list_t* last_el = NULL;
	list_t* next_el = head;
	list_t* curr_el = head;
	while(curr_el->next != NULL){
		next_el=curr_el->next;
		curr_el->next=last_el;
		last_el=curr_el;
		curr_el=next_el;
	}
	curr_el->next=last_el;
	head=curr_el;

	return head;
}

