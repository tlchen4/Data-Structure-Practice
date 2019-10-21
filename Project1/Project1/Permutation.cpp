#include <stdio.h>

//this function will create a list of consecutive integers up to an entered positive integer (max 7 for now)


void swap(int* arraypoint, int a, int b)
{
	int temp;
	temp = arraypoint[a];
	arraypoint[a] = arraypoint[b];
	arraypoint[b] = temp;
}

void ArrayPrint(int* List, int size) {
	//if you pass the pointer to first element in array, then you can use it just like an array inside the function
	for (int i = 0; i < size; i++) {
		if (i % 10 == 0) {
			printf("\n");
			//print in lines of 10 numbers at a time
		}
		printf("%d ", List[i]);

	}
	printf("\n");

}

int permute(int* arraypoint, int current, int end, int*checker_point)
{
	
		for (int i = current; i <= end; i++) {
			swap(arraypoint, current, i);
		
			if(current + 1 == end){
				ArrayPrint(arraypoint, end + 1);
				*checker_point = *checker_point + 1;
				}
			else {
				permute(arraypoint, current + 1, end, checker_point);
				
			}
			swap(arraypoint, current, i);
			
		}
		return *checker_point;

}


void Permutation(int* arr,int size) {
	//below 3 lines are sample data used during testing
	//int data[5] = { 1, 2, 3,4,5};
	//int* datapointer = &data[0];
	//int size = *(&data + 1) - data;

	

	//int ssize = *(&arr + 1) - arr; //something weird happens when we try to calculate size on an array that is passed in as a function argument...
	//printf("Ssize is %d", ssize); //returns something in the 100,000's , probably an address?
	int checker;
	checker = 0;

	checker=permute(arr, 0, size-1,&checker);
	printf("Number of permutations printed is %d\n", checker);

	
	//pass pointer to first element in array
	//checker is just to make sure the correct number of permutations were made, can remove later if needed
	return;
}


