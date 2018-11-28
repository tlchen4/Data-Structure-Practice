#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "Header.h"


using namespace std;


//declare pointer to node that is called head. note how we don't define node here
struct minmax {
	int min;
	int max;

};



minmax* Extrema(Node* head) {
	minmax* mm = new minmax;
	Node* traverse = head;
	//need to rewrite this for linked list instead of array -> Done.
	mm->min = head->data;
	mm->max = head->data;
	//initialize to the first item in the list
	while (traverse != NULL) {
		if (traverse->data < mm->min) {
			mm->min = traverse->data;
		}
		if (traverse->data > mm->max) {
			mm->max = traverse->data;
		}
		traverse = traverse->next;

	}
	return mm;
}


//directly edit the values in address of the global structure mm instead of returning a structure

void SingleList() {
	clock_t t;
	t = clock();
	srand(time(NULL));
	Node *head, *SearchIndexHead;
	head = NULL;
	int flag = 1;
	int decision, x, n, SearchValue;
	head = list(head);

	minmax * mimax;
	while (flag == 1) {
		printf("What would you like to do? \n");

		printf("\n");
		printf("0 - Main Menu \n");
		printf("1 - Insert Number \n");
		printf("2 - Delete Number \n");
		printf("3 - Reverse the list \n");
		printf("4 - Find min and max value in list \n");
		printf("5 - Search for a particular value in list \n");
		printf("6 - Sort the List \n");
		printf("7 - Print the list \n");
		printf("8 - Export LL to Array \n");
		printf("9 - Size of list \n");
		scanf_s("%d", &decision);

		switch (decision) {
		case 0:
			flag = 0;
			break;
		case 1:
			printf("Enter a number \n");
			scanf_s("%d", &x);
			printf("At what position do you want to insert this number? \n");
			scanf_s("%i", &n);
			head = Insert(head, x, n);
			LinkedPrint(head);
			break;
		case 2:
			head = Deletion(head);
			break;
		case 3:
			head = Reverse(head);
			//head = RecursionReverse(head);
			break;
		case 4:
			mimax = Extrema(head);
			printf("The minimum of this list is %d \n", mimax->min);
			printf("The maximum of this list is %d \n", mimax->max);
			printf("\n");
			break;
		case 5:
			printf("Enter the number you want to search for ");
			scanf_s("%i", &SearchValue);
			SearchIndexHead = LinearSearch(head, SearchValue);

			if (SearchIndexHead != NULL) {
				printf("\n");
				printf("The position(s) that %d were found are: ", SearchValue);
				LinkedPrint(SearchIndexHead);
				printf("\n");
			}
			else {
				printf("%d was not found in the list \n", SearchValue);

			}

			break;
		case 6:
			head = InsertionSort(head);
			break;
		case 7:
			LinkedPrint(head);
			RecursivePrint(head);
			printf("\n");
			break;
		case 8:
			int* arr;
			arr = toArray(head);
			int size;
			size = ListSizer(head);
			printf("The size of the list is %d \n", size);
			ArrayPrint(arr, size);
			delete arr; //destroy array lul
			arr = NULL;
			break;
		case 9:
			
			printf("The list size is %d \n",ListSizer(head));
			break;
		default:
			printf("Invalid Input, please try again \n");
			break;


		}

		cin.get();
		//	printf("%p \n", p);

	}


	t = clock() - t;

	printf("Program Runtime: %f seconds", ((float)t) / CLOCKS_PER_SEC);


	cin.get();

	//ask for user input (any input) before returning 0 and closing the program



	



}


//features to add: reverse list, delete node from nth position
//sort list ascending, sort list descending (try implementing different kinds of sort)