#ifndef Header_h
//if header_h is not defined (note we technically didn't need to call it Header_h, could've named it potato as long as we #define potato below)
// then execute the following code until endif:
//i suppose we should make separate headers since not every .cpp file needs to call every function in header_h
#define Header_h

struct Node {
	int data;
	Node* next;
};
Node* list(Node* head);
Node* Insert(Node* head, int x, int n2);
Node* Deletion(Node* head);

void LinkedPrint(Node* head);
void RecursivePrint(Node* traverse);
void ArrayPrint(int List[], int size);

int ListSizer(Node* head);
Node* Reverse(Node* head);
Node* RecursionReverse(Node* p);

Node* LinearSearch(Node* head, int SearchValue);

Node* InsertionSort(Node* head);
Node* InsertionSortAsc(Node* head);
Node* InsertionSortDesc(Node* head);

int* toArray(Node* head);


//extern Node *head;
//makes head global essentially, or head is already global cause its dfined outside main, but other files dont see it, this lets other files see it
#endif