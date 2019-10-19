#include <stdio.h>
#include "Main_Header.h"

void ArrayMain() {

	int arraysize;
	printf("How large of an array do you want?\n");
	scanf_s("%d", &arraysize);



	int decision, x;
	int flag = 1;

	while (flag == 1) {
		printf("0-Quit\n1-Recreate Array\n2-Sort Array\n3-Permute Array\n");
		scanf_s("%d", &decision);

		switch (decision) {

		case 0:
			flag = 0;
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			Permutation();
			break;
		default:
			printf("Invalid option, please try again\n");
			break;
		}
		return;
	}
}