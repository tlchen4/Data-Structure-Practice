#include <stdio.h> //printf, scanf, NULL
#include "ArrayHeader.h"
#include <time.h> //time
#include <stdlib.h> //srand, rand


void ArrayMain() {
	srand(time(NULL));
	int arraysize;
	printf("How large of an array do you want?\n");
	scanf_s("%d", &arraysize);
	int* arr = new int[arraysize]; //this way of allocating dynamic memory gets kinda messy later, works but is less robust
	
	
	for (int i = 0; i < arraysize; i++) {
		arr[i] = rand() % 100 + 1; //rand 100 generates a number in the range 0 to 99 , so rand()+1 is 1 to 100
	}
	
	printf("Your array is\n");
	ArrayPrint(arr, arraysize);
	
	//int calculatedsize = sizeof(arr)/sizeof(arr[0]);
	//printf("calculated size is %d, input size is %d\n", calculatedsize, arraysize);

	int decision;
	int flag = 1;

	while (flag == 1) {
		printf("0-Quit\n1-Randomize new numbers\n2-Sort Array\n3-Permute Array\n");
		scanf_s("%d", &decision);

		switch (decision) {

		case 0:
			flag = 0;
			break;
		case 1:
			for (int i = 0; i < arraysize; i++) {
				arr[i] = rand() % 100 + 1; //rand 100 generates a number in the range 0 to 99 , so rand()+1 is 1 to 100
			}

			printf("Your new array is\n");
			ArrayPrint(arr, arraysize);
			break;
		case 2:
			ArraySort(arr,arraysize);
			break;
		case 3:
			Permutation(arr,arraysize);
			break;
		default:
			printf("Invalid option, please try again\n");
			break;
		}
		

	}
	delete arr;
	return;
}