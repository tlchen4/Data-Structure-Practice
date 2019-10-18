#include <stdio.h>
#include <stdlib.h>
#include "Header_Double.h"


int ListSizer2(NodeDouble* head) {
	int i = 0;
	NodeDouble* traverse = head;

	while (traverse != NULL) {
		traverse = traverse->next;
		i++;

	}

	return i;

}


void DLinkedPrint(NodeDouble* head) {
	NodeDouble *traverse = head;


	while (traverse != NULL) {
		printf("%d ", traverse->data);
		traverse = traverse->next;
	}

	printf("\n");

}


NodeDouble* InsertDouble(NodeDouble* head, int x,int n) {
	//we'll just write it to insert in position 1 for now
	if (n == 1) {
		NodeDouble* temp = new NodeDouble;
		temp->prev = NULL;
		temp->next = head;
		temp->data = x;
		head = temp;
		return head;
	}
	else if (n > 1) {
		NodeDouble* temp = new NodeDouble;
		NodeDouble *traverse = head; //traverse now points to first node
		temp->data = x;

		int listsize;
		int i = 1;
		listsize = ListSizer2(head);
		if (n > listsize+1) {
			printf("There are not that many positions in this list. Setting n to last position \n");
			n = listsize+1;
		}
		while (i < n - 1) {

			traverse = traverse->next;
			//on first iteration we go from pointing at first node to pointing at 2nd node
			//traverse starts at head, if n=2 then we do nothing since the while loop doesn't execute
			//point at one node before n
			i++;
						
		}
		temp->next = traverse->next;
		temp->prev = traverse;
		if (traverse->next != NULL) {
			traverse->next->prev = temp;
		}
		traverse->next = temp;
		

		return head;

	}
	else {
		printf("Invalid n \n");

		return head;
	}

	
}

NodeDouble* DeleteDouble(NodeDouble* head, int n) {
	if (n == 1) {
		NodeDouble* temp;
		temp = head;
		head = head->next;
		delete temp;
		
		return head;
	}
	else if (n > 1) {

		NodeDouble* traverse=head;
		int listsize;
		int i = 1;
		listsize = ListSizer2(head);
		if (n > listsize) {
			printf("There are not that many positions in this list. Setting n to last position \n");
			n = listsize;
		}
		while (i < n ) {

			traverse = traverse->next;
			//on first iteration we go from pointing at first node to pointing at 2nd node
			//we want to point to the node that we want to delete
			i++;

		}
		traverse->prev->next = traverse->next;
		//chained arrows does work by the way
		delete traverse;
	}

	else {
		printf("Invalid input \n");
		return head;

	}

}

NodeDouble* DoubleListCreate(NodeDouble* head){
	int x;
	int n;
	printf("Enter the number of items in your list \n");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		x = rand() % 1000 + 1;
		/* Commented out user input
		printf("Enter a number \n");
		scanf_s("%d", &x);
		*/
		head = InsertDouble(head, x, 1);
		//do NOT print list at each step, gonna get messy if you do
		//if we randomly generate numbers, it doesn't really matter where we stick them, so stick them to front of list
	}
	return head;
}


void DoubleList() {
	int flag = 1;
	int decision;
	NodeDouble* head;
	head = NULL;
	while (flag == 1) {

		printf("What would you like to do? \n");

		printf("\n");
		printf("0 - Main Menu \n");
		printf("1 - Create a list \n");
		printf("2- Insert a Number \n");
		printf("3 - Delete a Number \n");
		printf("4 - Print the list \n");
		scanf_s("%d", &decision);

		switch (decision) {

		case 0:
			flag = 0;
			break;
		case 1:
			//head=DoubleListCreate(head);
			head=InsertDouble(head,5, 1);
			head=InsertDouble(head, 2, 1);
			head=InsertDouble(head, 1, 2);
			//printf("The list size is %d", ListSizer2(head));

			break;
		case 2:
			if (head == NULL) {
				head = DoubleListCreate(head);
			}
			else {
				int x, n;
				printf("What integer do you want to insert? \n");
				scanf_s("%d", &x);
				printf("What position do you want to insert it at? \n");
				scanf_s("%d", &n);

				head = InsertDouble(head, x, n);

			}
			
			break;
		case 3: 
			int n2;
			printf("What position do you want to delete? \n");
			scanf_s("%d", &n2);
			DeleteDouble(head, n2);
		case 4: 
			DLinkedPrint(head);
			break;
		default:
			printf("Invalid input \n");
			break;




		}



	}




}
