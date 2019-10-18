#include <stdio.h>

void StackLinkedList();
	//tell this file/functions that this given function exists somewhere

//nevermind i think we will just pass in original a and be careful not to modify a[0]

int* ExpandArray(int *arr); //declare this function, well only useful if a function before full definition uses this function....

int Push(int x, int top, int *a) {
	
	//printf("True size is %d \n", (a - 1)[0]-1);
		//the a that we pass in is pointer to the 2nd element of the true array, but as far as the function is concerned a is the start
		//a-1 tels function access the value in an array that starts 1 integer(?) unit back which is the start of the true array

	//each int takes up 4 byte sizeof(A) gives 40 , thus sizeof(A)/sizeof(A[0]) will give 40/4 = 10 which is the correct size of A
	//the type size_t is an unsigned integer type, it is the type returend by sizeof operator
	//well this assumes A is pointer to an entire array and not just pointer to first element, if it is pointer to first element like it is in this case sizeof(A)/sizeof(A[0]) will return 1 cause it's size of one integer in top and bottom 
	
	if (top < a[0]-1) {
		//(a-1)[0] contains the true size of the list, but what we really need is minus 1 because one slot is the size of the array and not the actual list
		//for list of size 10, (a-1)[0] will be 10, so (a-1)[0]-1 will be 9
		//we can only use top as indexes for a (which is truncated) from 0 to 8 (9 elements)
		top = top + 1;
		a[top] = x;
		
	}
	else {
		printf("The list is full. \n"); 
		
	}
	return top;

}

int Pop(int top) {

	if (top > 0) {
		top = top - 1; //don't need to remove value before moving top, we will just overwrite it when we push again
		printf("Top is now %d. \n", top);
	}
	else {
		printf("The list is empty; there is nothing to push. \n");

	}
	return top;
}

void StackPrint(int *point, int top){
	//note we pass in the entire array, but we want to avoid using point[0] because that's not our actual list
	printf("The list is: ");
	for(int i=1; i<=top; i++){

		printf("%d ", point[i]);



	}


}

int* ExpandArray(int *arr){
	//pass in address of first element of previous array. note first element of arr contains size information
	//runs in O(n)
	int *temp = new int[2 * arr[0]]; //create new array of integers that is size 2*arr[0] , aka twice the size of the old array

	for (int i = 0; i < arr[0]; i++) {
		temp[i] = arr[i];
		//copy elements of old arr into temp in the same order, note this includes copying value of old array's size
	}

	
	temp[0] = 2 * temp[0]; //update size information to be twice the size of the old array
	

	delete arr; //delete old array

	return temp; //return address of temp, which is pointer to first element of the new array



}


void StackMain() {
	int flag = 1;
	int x;
	int* arr= new int[10];
	arr[0] = 10; 
	//pointer to first element in array contains no size information on its own, thus we will use first element in array to contain size of entire array, including that element
	//note the name arr itself is a pointer to first element of the array aka arr is same as &arr[0]
	int top = 0; //need top to start at 0, 0 is offlimits since it contains size, the true array starts at 2nd element in the array
	
	printf("Size is %d \n", arr[0]);
	
	int decision;
	while (flag == 1) {
		printf("What would you like to do? \n");
		printf("0-Quit\n1-Push\n2-Pop \n3-Print \n4-Expand Array \n5-Stack with LinkedList \n");
		scanf_s("%d", &decision);
		switch (decision) {
		case 0:
			flag = 0;
			break;
		case 1:
			printf("What would you like to push?\n");
			scanf_s("%d", &x);
			top=Push(x, top, arr);
			
			break;
		case 2:
			top=Pop(top);
			break;
		case 3:
			printf("Value of top is %d.\n Size is %d \n", top, arr[0]);
			StackPrint(arr, top);
			//start printing the array from the 2nd index (to StackPrint it will be as if we were printing from the first index, but it doesn' t know we hid 1 element from it)
			
			break;
		case 4:
			arr=ExpandArray(arr);
			break;

		case 5:
			StackLinkedList();
			break;

		default:
			printf("Invalid input \n");
			break;


		}

		
	}
	delete arr; //delete arr when we are done with stack.
		
	

	//Push(2, top, point);







}