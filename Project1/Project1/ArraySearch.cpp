#include <stdio.h>


int BinarySearch(int List[], int x, int size) {
	//x is the value being searched for , return an integer that corresponds to its index in the given array
	//THE LIST MUST BE SORTED FOR THIS TO MAKE SENSE

	int left = 0; //represent the left side of list
	int right = size; //we may want to keep size of list for other purposes, use a temp variable right that we can freely modify



	while (left <= right) {
		int Mid = left + (right - left) / 2; //need to recalculate Mid at the start of each while execution. The "left" gives us our basis/starting point. Initially it is 0 but that could change (aka our new 0 gets moved up)
											 //for lists of even size this will give the first index of the upper half. for odd lists this will actually give the 1 index after the true center (which is fine for our purposes)
											 //the key is that when left=right then Mid=left=right due to the way 0.5 gets cut off
											 //actually left+(right-left)/2 is better than summing left and right cause less chance of overflow. left+right could be massive , but left+(right-left)/2 would be smaller to work with
		if (List[Mid] == x) {
			return Mid;

		}
		else if (List[Mid] < x) {
			left = Mid + 1;
		}
		else { //this case handles when x is less than List[Mid] , move the right index to Mid-1 (1 index before current Mid)
			right = Mid - 1;

		}
	}
	return -1; //return -1 if nothing was found

}