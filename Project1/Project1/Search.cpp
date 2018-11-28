#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <time.h>

Node* LinearSearch(Node* head, int SearchValue) {
	Node* traverse = head;
	Node* SearchHead;
	clock_t t;
	t = clock();

	SearchHead = NULL;
	int i = 1; //keep track of what position we are on

	while (traverse != NULL) {
		if (traverse->data == SearchValue) {
			Node* temp = new Node;
			temp->data = i;
			temp->next = SearchHead;
			SearchHead = temp;
			//create another linked list to store the positions that we found the SearchValue in, for the original list
			//this list only needs to insert at the beginning
			traverse = traverse->next; //move onto next node
		}
		else {
			traverse = traverse->next;
			//move onto next node without doiing anything if data does not match search value

		}

		i++;  //update position tracker as we start next iteration


	}
	t = clock() - t;

	printf("Search time: %f seconds", ((float)t) / CLOCKS_PER_SEC);


	return SearchHead;
	//return the head of the linked list of positions
			
}

//Node* BinarySearch(Node* head, int Searchvalue)
//maybe just have it run sort on the list to make sure the input is a sorted list, or ask for user input , is this list sorted? y/n
//need input of a sorted list for BinarySearch though
//Binary search isn't great for linked list


