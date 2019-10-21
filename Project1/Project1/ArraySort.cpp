#include <stdio.h>
#include "Main_Header.h"

void merger(int* arr, int left, int right, int mid) {
	//re-merges two sorted halves of an array into a single sorted piece
	//first piece has first index at left until and including mid, second piece will start at mid+1 and continue up to and include index "right"
	int n1, n2;
	//n1 and n2 will be the size (number of elements) in first and second array respectively
	//note that the two pieces are assumed to have been already sorted
	n1 = mid - left + 1;
	n2 = right - mid;

	//we will need to create a temporary variable to use as a floating placeholder as we compare the left piece vs the right piece and a second placeholder for when we need to re-insert the placeholder itself back into the array
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
	//i will be used to track the current position in temporary left list, j for temporary right list, k for current position of insertion for original array
	while (i < n1 || j<n2) {
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


void ArraySort() {
	int Arr[5] = {5,9,1,2,3};
	merger(Arr, 0, 4, 2);
	ArrayPrint(Arr, 5);
	
	return;
}