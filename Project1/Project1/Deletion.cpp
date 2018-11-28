#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

//testing 123

Node* Delete_Position(Node* head, int n) {
	Node *traverse = head;
	int listsize;
	listsize = ListSizer(head);
	if (n > listsize) {
		printf("That position does not exist. Deleting last element in list.\n");
		n = listsize;
		
	}
	//the head node itself is already pointing the the first node
	//thus traverse pointer = head means traverse also points to node 1. it does NOT point to head
	if (n == 1) {
		head = traverse->next;
		delete traverse;
		LinkedPrint(head);
		return head;
		//return so we don't execute any of the stuff below
	}

	int i = 1;
	//this should be robust for i >1. If i=2 ,the nothing happens and we start at traverse=head
	//to delete at position n, we first need to traverse the list
		while (i < n-1) {
			traverse = traverse->next;
			//traverse starts at 1st node and traverses
			i++;
			// we need to traverse the list to the n - 1th position
			//(via address of n-1th node stored in n-1th node)
			// we also need the address of nth position so we can read the "next" value from the node at that address
		}
		Node *temp = traverse->next;
		//for n=2, temp now points to node 2
		temp = temp->next;
		//obtain address data from nth node
		delete traverse->next;
		//delete data stored in nth node which is what traverse->next points to
		traverse->next = temp;
		//set "next" address of n-th node to the node that was deleted
		LinkedPrint(head);
	
		return head;
		//we need to replace the n-1th address with the address at nth position
		//then we need to delete nth position from the memory , so we still need pointer to that position
}
Node* Delete_Number(Node* head, int n) {
	Node* traverse = head;
	Node* prev = NULL;
	//int i = 1; //need to keep track where we are in the list , will be in reference to original list (before deletions) , shouldn't be a problem if we go straight through and never look back
	while (traverse != NULL) {
		if (traverse->data == n) {
			if (head == traverse) {
				//if head and traverse point to the same node, it's the first node
				head = traverse->next;
				Node* current = traverse; //need to save current position before we delete the node
				delete traverse; //I'm hoping this only deletes the contents in traverse, but the variable traverse is still good to take new values;
				traverse = head; //move onto next node
			}
			else {
				prev->next = traverse->next; //skip the node that is about to be deleted
				delete traverse;
				traverse = prev->next; //move onto next node
			}
			
		}
		else {
		prev = traverse;
		traverse = traverse->next;
		//move onto next node without doiing anything if data does not match search value


		}

	//i++;  //update position tracker as we start next iteration

		
	}
	printf("The list is now: ");
	LinkedPrint(head);
	printf("\n");
	return head;
}

Node* Deletion(Node* head) {
	int n_del,type;
	int flag = 0;
	while (flag == 0) {
		printf("Enter 1 to delete by position. Enter 2 to delete by number \n");
		scanf_s("%d", &type);
		switch (type) {
			case 1:
				printf("Which position do you want to delete? \n");
					scanf_s("%d", &n_del);
				head=Delete_Position(head, n_del);
				flag = 1;
				break;
			case 2:
				printf("What number do you want to delete?\n");
				scanf_s("%d",&n_del);
				head=Delete_Number(head,n_del);
				flag = 1;
				break;
				
			default:
				printf("Invalid input. Please try again \n");
				break;

		}
	
	}

	return head;
}
