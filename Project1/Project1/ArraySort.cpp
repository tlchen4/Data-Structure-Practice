#include <stdio.h>

int* merger(int* arr, int left, int right, int mid) {
	//re-merges two sorted halves of an array into a single sorted piece
	//first piece has first index at left until and including mid, second piece will start at mid+1 and continue up to and include index "right"
	int n1, n2;
	//n1 and n2 will be the size (number of elements) in first and second array respectively
	//note that the two pieces are assumed to have been already sorted
	n1 = mid - left + 1;
	n2 = right - mid;

	//we will need to create a temporary variable to use as a floating placeholder as we compare the left piece vs the right piece and a second placeholder for when we need to re-insert the placeholder itself back into the array
	int placeholder1, placeholder2;
		//In C++, the size of the array in stack memory must be known at compile time. We cannot have a scenario where the size is only known at runtime. We could make it create an array in heap memory with the new function though.
		//hence why we're using a single variable to do the data manipulations instead of creating two extra copies of the left and right piece and comparing those pieces while re-inserting back to the original array
		//we could do that, but we would need a lot of "new" and "delete" functions to make it work
	for (int i = 1; i <= (n1 + n2); i++) {
		//i will represent the number of elements inserted, i=1 will represent re-insertion of first element in arr, continue until n1+n2 elements (aka total size of the left+right pieces) are re-inserted in sorted order
		if (i == 1) {

			if (arr[left] <= arr[right]) {

				



			}

		}
		else if(arr[left]<)

	}


}