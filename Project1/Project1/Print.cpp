#include <stdlib.h>
#include <stdio.h>
#include "Header.h"
void ArrayPrint(int List[], int size) {

	for (int i = 0; i < size; i++) {
		if (i % 10 == 0) {
			printf("\n");
			//print in lines of 10 numbers at a time
		}
		printf("%d ", List[i]);


	}
	printf("\n");

}

void LinkedPrint(Node* head) {
	Node *traverse = head;


	while (traverse != NULL) {
		printf("%d ", traverse->data);
		traverse = traverse->next;
	}

	printf("\n");

}


void RecursivePrint(Node* traverse) {
	if (traverse == NULL) {
		printf("\n");
		return;
	}
	RecursivePrint(traverse->next); //put prinf before recursive call to print in forward order, put printf after recursive call to print in reverse order
	printf("%d ", traverse->data);
		
	
}
