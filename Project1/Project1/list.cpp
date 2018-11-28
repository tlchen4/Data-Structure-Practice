#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h";

//need to include "Header.h" to get the global info on what a node is
 using namespace std;


Node* Insert(Node* head, int x , int n2) {
	if (n2 == 1) {
		Node* temp = new Node;
		temp->data = x;
		temp->next = head;
		head = temp;
		return head;
	}

	else if (n2 > 1) {
		int listsize;
		listsize = ListSizer(head);
		
		Node *temp = new Node;
		Node *traverse = head; //traverse now points to first node
		temp->data = x;
		int i = 1;
		if (n2 > listsize+1) {
			printf("There are not that many positions in this list. Setting n2 to last position \n");
			n2 = listsize+1;
		}

		while (i < n2 - 1) {
			
				traverse = traverse->next;
				//on first iteration we go from pointing at first node to pointing at 2nd node
				//traverse starts at head, if n=2 then we do nothing since the while loop doesn't execute
				i++;
					

			
			// I don't think the following comment is correct:  we need to traverse the list to the n - 2 position and get the value of address stored in the node there
			// aka we need the address of n-1 position. then we can read the "next" value from the node at that address
		}
		//if n=3, we exit while loop after 1 iteration cause 2 is not less than 2, thus traverse points at 2nd node
		temp->next = traverse->next;
		//traverse-> next currently points to 3rd node (for n=3) which will become the 4th node when we insert temp, so build link from temp to future 4th node
		traverse->next = temp; 
		//build link from 2nd node to inserted node using address of the inserted node
		
		//need an error handling if user tries to insert at point that doesn't exist in list, like position 1000 in list that is currently size 3
		return head;
		
	}

	else {
		//for n negative
		printf("Negative positions do not make sense, multiplying input by negative 1 (-5 will become 5th position)");
		n2 = -n2;
		int i = 1;
		Node *temp = new Node;
		Node *traverse = head;
		temp->data = x;

		//we'll start from the beginning of the list
		while (i < n2) {
			traverse = traverse->next;
			i++;
			//we need to traverse the list to the n-1 position and get the value of address stored in the node there
		}

		temp->next = traverse;
		//store address in n-1th position into our newly created node
		traverse->next = temp;
		//now that we've given the address of the n-1th node to temp, we need to modify the address of n-1th node to point to temp
		return head;
	}
	
	

}


int ListSizer(Node* head) {
	int i = 0;
	Node* traverse = head;
	
	while (traverse != NULL) {
		traverse = traverse->next;
		i++;

	}

	return i;

}

Node* list(Node* head) {
	int x, decision;
	int n, n2;
	
	
	printf("Enter the number of items in your list \n");
	scanf_s("%d", &n);
	printf("Would you like to automatically generate a list? 1-Yes , 2-No \n");
	scanf_s("%d", &decision);
	switch (decision) {
		case 1:
			for (int i = 0; i < n; i++) {
				x = rand() % 1000 + 1;
				/* Commented out user input
				printf("Enter a number \n");
				scanf_s("%d", &x);
				*/
				head = Insert(head, x, 1);
				//do NOT print list at each step, gonna get messy if you do
				//if we randomly generate numbers, it doesn't really matter where we stick them, so stick them to front of list
			}
			
			break;

		case 2:
			//i think argument of time is an option to store the value of time into the address of a pointer of type time_t
			for (int i = 0; i < n; i++) {
				x = rand() % 1000 + 1;
				/* Commented out user input
				printf("Enter a number \n");
				scanf_s("%d", &x);
				*/
				if (i == 0) {
					printf("The first number is %d \n", x);
					head = Insert(head, x, 1);
					LinkedPrint(head);
					//if this is the first number, then just insert as first position automatically
				}
				else {
					printf("Randomly generated number %d \n", x);
					printf("At what position do you want to insert this numnber? \n");
					scanf_s("%i", &n2);

					head = Insert(head, x, n2);
					LinkedPrint(head);

				}
			}
			
			break;
		default:
			printf("Invalid input. No list created \n");
			break;
			return head;
	}
	return head;
}
