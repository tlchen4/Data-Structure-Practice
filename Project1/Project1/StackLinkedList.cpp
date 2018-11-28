#include <stdlib.h>
#include <stdio.h>


struct Node {

	int data;
	Node* next;


};


Node* LinkedPush(Node* top, int x){
	Node* temp = new Node;

	temp->data = x;
	temp->next = top;
	top = temp;

	//for stack we only want to insert at beginning
	return top;
}

Node* LinkedPop(Node* top) {
	Node* temp; //will be used to contain address of node to be deleted
	
	if (top == NULL) {
		printf("The list is empty. \n");
		
	}
	else {
		temp = top;
		top = top->next;

		delete temp;
		temp = NULL;
	}

	return top;


}

Node* DeleteAll(Node* traverse) {
	//deletes all elements in the linked list
	Node* temp;

	while (traverse != NULL) {
		temp = traverse->next; //make sure to get address of next node before we delete current node
		delete traverse; //delete current ndoe
		traverse = temp;
	}

	
	
	
	return traverse; //traverse should be NULL at this point , so we return null pointer

}

void StackLLPrint(Node* traverse){

	if (traverse== NULL) {
		printf("\n");
		return;

	}
		
	StackLLPrint(traverse->next);
	printf("%d ", traverse->data);

	//should print list in reverse order such that the top of the list is printed on the rightmost side
}


void StackLinkedList(){

	Node* top = NULL;
	int decision,x;
	int flag = 1;
	while (flag == 1) {
		printf("0 - Quit\n1-Push\n2-Pop\n3-Print\n4-Delete All \n");
		scanf_s("%d", &decision);

		switch (decision) {

		case 0:
			flag = 0;
			break;
		case 1:
			printf("Enter an integer to push \n");
			scanf_s("%d", &x);
			top = LinkedPush(top, x);
			break;
		case 2:
			top = LinkedPop(top);
			break;
		case 3:
			printf("The current list is:");
			StackLLPrint(top);
			printf("\n");
			break;

		case 4:
			top = DeleteAll(top);
			break; //note these breaks arent a requirement, if they arent there , the function will just continue and execute subsequent cases, so switch is more like a "go-to" and tells 
			//the program where to start from and then it keeps going down and executing case(s) until it hits a break.
		default:
			printf("Invalid input.\n");
			break;



		}


	}

	

}