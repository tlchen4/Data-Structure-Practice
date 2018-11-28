#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

Node* Reverse(Node* head) {
	Node* current = head; 
	Node* prev = NULL;
	Node* next_node;
	
	while (current != NULL) {
		next_node = current->next;
		//store address of next node before we break the link
		current->next = prev;
		//break link and set link to point at previous node
		prev = current;
		//increment prev to be current node
		current = next_node;
		//move current to the next node

	}
	head = prev;
	return head;
	//when we exit loop, previous will point at last node (which will become the first node when we reverse the list)

}

Node* RecursionReverse(Node* p) {
	Node* head;
	if (p->next == NULL) {
		head = p;
		//we only want to return on the last one...not sure how the other recursive calls will handle this
		return head;

	}
	
	head=RecursionReverse(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
	return head;

	//each recursive call will return head given by its inner recursive call where the most inner call will set the value of head to where p currently points (last node at that point) then returns head



}
