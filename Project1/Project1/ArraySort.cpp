#include <stdio.h>
#include "ArrayHeader.h"

void merger(int* arr, int left, int right, int mid) {
	//re-merges two sorted halves of an array into a single sorted piece
	//first piece has first index at left until and including mid, second piece will start at mid+1 and continue up to and include index "right"
	int n1, n2;
	//n1 and n2 will be the size (number of elements) in first and second array respectively
	//note that the two pieces are assumed to have been already sorted
	//mid will be defined such that the leftlist will be the same size as rightlist or is +1 element larger than rightlist
	n1 = mid - left + 1;
	n2 = right - mid;

	int* leftlist = new int[n1];
	int* rightlist = new int[n2];
		//In C++, the size of the array in stack memory must be known at compile time. We cannot have a scenario where the size is only known at runtime. We can make it create an array in heap memory with the new function though.
		//recall the "new" operator returns a pointer to the address of the allocated space
	for (int i = 0; i < n1; i++) {
		leftlist[i] = arr[left + i];
	}
	
	for (int i = 0; i < n2; i++) {
		rightlist[i] = arr[mid + 1 + i];
		
	}
	
	//copy data into our temporary lists
	int i = 0;
	//re-initialize i
	int j = 0;
	int k = 0;
	//Index i will be used to track the current position in temporary left list, j for temporary right list, k for current position of insertion for original array
	
	while (i < n1 && j<n2) {
		//while will continue to loop until the statement is false, we require both i < n1 and j < n2 ,otherwise one of the lists is already used up
		//***something strange happens here when n = 4 or more...
		if (leftlist[i] <= rightlist[j]) {
			arr[k] = leftlist[i];
			i++;
		}
		else {
			arr[k] = rightlist[j];
			j++;

			}
		k++;
		
	}
		
	if (i == n1) {
		//this means left side finished first, still need to replace the rest of temporary rightlist into the remainder of the original array
		for (j; j < n2; j++) {
			arr[k] = rightlist[j];
			k++;

		}
	}
	else if(j==n2){
		//this means right side finished first
		for (i; i < n1; i++) {
			arr[k] = leftlist[i];
			k++;
		}
	}
	
	delete leftlist;
	delete rightlist;
	//free our temporary lists from memory before exiting the function since these variables persist even after the function is over
	
	return;
	//don't need to return anything if we directly modify the array via its address(and not a copy of it)
}

void mergesort(int* arr,int left,int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;// (left + right) / 2 is the same thing but if left and right are large you can get overflow error more easily
		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);
		merger(arr, left, right, mid);
	}
	
}


void ArraySort(int* arr, int size) {
		
	int decision, x;
	int flag = 1;
	

	while (flag == 1) {
		printf("0-Quit\n1-Print array\n2-Merge Sort\n");
		scanf_s("%d", &decision);

		switch (decision) {

		case 0:
			flag = 0;
			break;
		case 1:
			ArrayPrint(arr, size);
			break;
		case 2:
			mergesort(arr, 0, size - 1);
			break;
		default:
			printf("Invalid option, please try again\n");
			break;
		}

	}
	return;
}

/*
note using sizeof(arr)/sizeof(arr[0]) works too, both don't work if you only pass pointer to first element in array though i think...

pretend arr is an array of size 6 integers

&arr ==> Pointer to the entire array of 6 elements. vs arr (name of an array) is just pointer to the first element of the array

(&arr + 1) ==> Address of 6 integers ahead of arr since &arr itself is a block of 6, so the +1 element after it is 6 integers ahead of arr 
note arr+1 would be just the second element of the array

*(&arr + 1) ==> Same address as (&arr + 1), but
type of pointer is "int *".

*(&arr + 1) - arr ==> Since *(&arr + 1) points
to the address 6 integers
ahead of arr, the difference
between two is 6.
*/

/*
while (i < n1) {
//this means right side finished first, need to fill in rest of arr with the remainining elements of leftlist
arr[k] = leftlist[i];
i++;
k++;
}
while(j < n2){
//entering this loop means left side finished first
arr[k] = rightlist[j];
j++;
k++;

}
*/