#include <stdlib.h>
#include "Header.h"

int* toArray(Node* head){
	Node* traverse = head;
	int Size = 0;
	while (traverse != NULL) {
			traverse = traverse->next;
			Size++;




	}
	int *arr = new int[Size];
	traverse = head; //reset ntraverse to head
	for (int i = 0; i < Size; i++) {
		arr[i] = traverse->data;
		traverse=traverse->next;
			
	}


	return arr;
	//return pointer to the array we made. so apparently the array is not destroyed when this function ends if we use new operator


}