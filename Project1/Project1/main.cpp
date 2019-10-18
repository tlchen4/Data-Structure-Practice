#include <stdio.h>
#include "Main_Header.h"


int main() {
	int decision;
	int flag = 1;

	while (flag == 1) {
		printf("0 - Quit \n1-Singly Linked List \n2-Double Linked List \n3-Stack \n4-LLQueue\n5-Permutation \n");
		scanf_s("%d", &decision);

		switch (decision) {

		case 0:
			flag = 0;
			break;
		case 1:
			SingleList();
			break;

		case 2:
			DoubleList();
			break;
		case 3:
			StackMain();
			break;
		case 4:
			LLQueue();
			break;
		case 5:
			Permutation();
			break;
		default:
			printf("Invalid input. Please try again. \n");
			break;

		}

	}

	return 0;
}