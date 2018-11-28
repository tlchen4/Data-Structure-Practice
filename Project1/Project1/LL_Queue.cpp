#include <stdlib.h>
#include <stdio.h>


struct Node {

	int data;
	Node* next;


};

void LinkedEnQueue(Node** frontp, Node** tailp,int x){
	//pass in pointer to pointer so we can use this dummy function variable to modify the address of the pointer (front and tail) that we care about
	//pointer to pointer with only one dereference modifies the address of the inner pointer double dereference would grab the value that the inner pointer points to
	Node* temp = new Node;

	temp->data = x;
	temp->next = NULL;
	
	if (*frontp == NULL && *tailp == NULL) {
		*frontp = *tailp = temp;
		//front and tail will both point to this node if it is the first node created, note that after this, front will not change what it points to (the front of the line won't change with insertion operation)
		return;

	}
	(*tailp)->next = temp;
	//paranthesis because I think arrow operator takes precedence?
	//set "next" value of the current last node in linked list to the newly created node
	*tailp = temp;
	//set the value of tail to point at address of the newly inserted node
	


}
void LinkedDequeue(Node** frontp, Node** tailp) {
	Node* temp = *frontp;
	if (*frontp == NULL) {
		return;
		//do nothing if front is already pointing to nothing
	}
	if (*frontp == *tailp) {
		//dequeuing last element in the list, when on last element/list of 1 element front and rear will point at same element
		*frontp = *tailp = NULL;
		//set both to NULL

	}
	else {
		//if list is not empty or only one element
		*frontp = (*frontp)->next; //increment front to the next node in the list
		delete(temp); //free up the node we just removed from the memory , explicitly created nodes with new stick around in memory even after function that created them finishes running
		temp = NULL; //set pointer to NULL after we deleted the contents of the previous address. technically the pointer still exists, but it won't misbehave if it points to NULL

	}


}

int LinkedQueueEmpty(Node* front){
//returns 1 if list is empty , 0 otherwise
	if (front == NULL) {
		return 1;
		
	}

	return 0;



}

void LinkedQueueFront(Node* front) {
//print value of top of list
	if (front == NULL) {
		printf("The list is empty \n");
		return;

	}
	printf("The value at the top is currently: %d \n", front->data);


}
void QueuePrint(Node* front) {
	if (front == NULL) {
		printf("The list is empty\n\n");
		return;

	}
	Node* temp = front;
	while (temp != NULL) {

		printf("%d ",temp->data);
		temp = temp->next;


	}
	printf("\n");


}
void LLQueue(){
	Node* front = NULL;
	Node* tail = NULL;
	Node** frontp = &front;
	Node** tailp = &tail;
	//read values from the front of the list
	//insert things at the end aka "tail" of the list

	int decision, x;
	int flag = 1;

	while (flag == 1) {
		printf("0-Quit\n1-Insert integer\n2-Check if list is empty\n3-Dequeue\n4-Read top value\n5-Print Whole List\n");
		scanf_s("%d", &decision);

		switch (decision) {

		case 0:
			while (front != NULL) {
				LinkedDequeue(frontp, tailp);

			}

			flag = 0;
			break;
		case 1:
			printf("Enter an integer to push \n");
			scanf_s("%d", &x);
			LinkedEnQueue(&front, &tail, x);
			//pass in pointers to front and tail
			break;

		case 2:
			int IsEmpty;
			IsEmpty = LinkedQueueEmpty(front);
			IsEmpty == 1 ? printf("List is currently empty\n") : printf("List is not empty\n");

			break;
		case 3:
			LinkedDequeue(frontp, tailp);
			break;
		case 4:
			LinkedQueueFront(front);
			break;
		case 5:
			QueuePrint(front);
			break;
		
		}
		
	}

}
