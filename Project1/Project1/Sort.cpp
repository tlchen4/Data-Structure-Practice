#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Header.h"

//BubbleSort

Node* InsertionSort(Node* head) {
	int decision;
	printf("1- Sort Ascending 2- Sort Descending \n");
	
	scanf_s("%d", &decision);

	switch (decision) {
	case 1:
		head=InsertionSortAsc(head);
		break;
	case 2:
		head = InsertionSortDesc(head);
		break;
	default: 
		printf("Invalid input. Returning to main menu \n");
		break;


	}

	return head;

}
Node* InsertionSortAsc(Node* head){
	
	//hard to scan backwards in singly linked list , might be better to swap to the right for > instead of to the left for <=
	clock_t t;
	t = clock();
	Node* traverse = head;
	Node* prev=NULL; //avoid starting with prev to NULL
	//these need to be defined outside the while loop for which they are used to traverse otherwise we keep resetting to the beginning
	
	while (traverse != NULL) {
		int SortCheck = 0;
		Node* prev2 = NULL;
		Node* traverse2 = head;


		while (traverse2 != traverse) {
			if (traverse->data < traverse2->data) {
				// > for sort descending, < for sort ascending, essentially if it meets something of same value it wont do anything so we preserve stability
				if (prev2 == NULL)
				{
					head = traverse;
					prev->next = traverse->next;
					traverse->next = traverse2;
					traverse = prev->next;
					SortCheck = 1;
					break;

				}
				else {
					prev2->next = traverse; //build link from previous node to node we have currently traversed to, effectively inserting the node right before traverse2's node
					prev->next = traverse->next; //save the link to the next node
					traverse->next = traverse2; //complete insertion to be right before the node that we were less than
					traverse = prev->next; //reset traverse to point at the next node
					//don't want to point at the node way back there, point at what is the next node, this effectively moves us to the next node
					SortCheck = 1; //tell that we've made an insertion which already includes the incrementation step

					break;
				}
			}
			else {

				prev2 = traverse2;
				traverse2 = traverse2->next;

			}
						
		}
		if(SortCheck == 0){
			//only increment to next node if we did not sort since the sort step includes a increment step in it already
			prev = traverse;
			traverse = traverse->next;
		}
	}

	

	//should work for n=1 or more, if n=1 the while loop won't execute and we just return head which is the sorted list of n=1 size
	//should also work for empty list since head is NULL
	
	t = clock() - t;

	printf("Sort time: %f seconds \n", ((float)t) / CLOCKS_PER_SEC);
	//head = Reverse(head); //makes list ascending...lots of extra computation though
	return head;

}
Node* InsertionSortDesc(Node* head) {

	//hard to scan backwards in singly linked list , might be better to swap to the right for > instead of to the left for <=
	clock_t t;
	t = clock();
	Node* traverse = head;
	Node* prev = NULL; //avoid starting with prev to NULL
					   //these need to be defined outside the while loop for which they are used to traverse otherwise we keep resetting to the beginning

	while (traverse != NULL) {
		int SortCheck = 0;
		Node* prev2 = NULL;
		Node* traverse2 = head;


		while (traverse2 != traverse) {
			if (traverse->data > traverse2->data) {
				// > for sort descending, < for sort ascending, essentially if it meets something of same value it wont do anything so we preserve stability
				if (prev2 == NULL)
				{
					head = traverse;
					prev->next = traverse->next;
					traverse->next = traverse2;
					traverse = prev->next;
					SortCheck = 1;
					break;

				}
				else {
					prev2->next = traverse; //build link from previous node to node we have currently traversed to, effectively inserting the node right before traverse2's node
					prev->next = traverse->next; //save the link to the next node
					traverse->next = traverse2; //complete insertion to be right before the node that we were less than
					traverse = prev->next; //reset traverse to point at the next node
										   //don't want to point at the node way back there, point at what is the next node, this effectively moves us to the next node
					SortCheck = 1; //tell that we've made an insertion which already includes the incrementation step

					break;
				}
			}
			else {

				prev2 = traverse2;
				traverse2 = traverse2->next;

			}

		}
		if (SortCheck == 0) {
			//only increment to next node if we did not sort since the sort step includes a increment step in it already
			prev = traverse;
			traverse = traverse->next;
		}
	}



	//should work for n=1 or more, if n=1 the while loop won't execute and we just return head which is the sorted list of n=1 size
	//should also work for empty list since head is NULL

	t = clock() - t;

	printf("Sort time: %f seconds \n", ((float)t) / CLOCKS_PER_SEC);
	//head = Reverse(head); //makes list ascending...lots of extra computation though
	return head;

}
//MergeSort