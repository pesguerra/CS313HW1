/*
*	@Paolo Esguerra
*	@CSCI-313
*	@Group 6
*	@Date: 3/24/21
*	HW 1 Program 2
*	Test whether a recursive, iterative or linked-type binary search is faster by testing it on
*	arrays of sizes 1 million and 10 million with arrays that are filled with random numbers.
*	You will need to either fill it in a “sorted way” or sort it before doing the binary search.
*/

#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std::chrono;
using namespace std;

//node class declaration
class Node {
public:
	int data;
	Node* next;
};

//function to insert a node
void insert(Node** head, int val)
{
    Node* temp = new Node;
    Node* ptr;
    temp->data = val;
    temp->next = NULL;
  
    if (*head == NULL)
        *head = temp;
    else {
        ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

//function to fill a Linked List with values from an array passed through the parameter along with the size of the array
Node *arrayToList(int arr[], int size)
{
    Node *head = NULL;
    for (int i = 0; i < size; i++) {
        insert(&head, arr[i]);
    }
    return head;
}

//function to find the middle element of the passed Linked List using the fast and slow pointers concept
Node* middle(Node* start, Node* last) 
{ 
    if (start == NULL) 
        return NULL; 
  
    Node* slow = start; 
    Node* fast = start; 
  
    while (fast != last && fast->next != last) 
    {  
        if (fast != last) 
        { 
            slow = slow -> next; 
            fast = fast -> next -> next; 
        } 
    } 
  
    return slow; 
}

//function to implement a binary search using the Linked List data structure 
Node* linkedBinary(Node *head, int val) 
{ 
    Node* start = head; 
    Node* last = NULL; 

    do
    { 
        Node* mid = middle(start, last); 
        if (mid == NULL) 
            return NULL;
            
        if (mid -> data == val) 
            return mid; 
        else if (mid -> data < val) 
            start = mid -> next;  
        else
            last = mid; 
  
    } while (last == NULL || (last != start)); 
  
    // When value not found 
    return NULL; 
} 

//function to implement a recursive binary search
//output is the index at which the desired int x is found or -1 which indicates not found inside passed array
int recursive(int arr[], int l, int r, int val) {	
	if (r >= l) { 
        int mid = l+(r-l) / 2; 
        if (arr[mid] == val) {
            return mid;
        }
		if (arr[mid] < val) {
        	return recursive(arr, mid+1, r, val); 
		}
        return recursive(arr, l, mid-1, val);
    } 
    return -1;
}

//function to implement an iterative binary search
//output is the index at which the desired int x is found or -1 which indicates not found inside passed array
int iterative(int arr[], int l, int r, int val) {
	while (l <= r) { 
        int mid = l+(r-l) / 2; 
        if (arr[mid] == val) {
            return mid;
        }
        if (arr[mid] < val) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    } 
    return -1;
}


int main() {
	
	//Declare const sizes to be used
	int const SIZE1 = 1000000;
	int const SIZE2 = 10000000;
	//arbitrary int value to search for
	int const VAL = 12345;
	
	//Declare and instantiate arrays of sizes 1 million and 10 million on heap
	int *arr1 = new int[SIZE1];
	int *arr2 = new int[SIZE2];
	
	srand(time(nullptr));
	
	//fill arrays with random numbers using rand()
	for(int i=0; i<SIZE1; i++) {
		*(arr1 + i) = rand() % SIZE1 + 1;
	}
	for(int j=0; j<SIZE2; j++) {
		*(arr2 + j) = rand() % SIZE2 + 1;
	}
	
	//sort both arrays using sort function in algorithm library
	auto start = high_resolution_clock::now();
	sort(arr1, arr1 + SIZE1);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to sort array of size 1 million: " << duration.count() << " microseconds" << endl;
	
	start = high_resolution_clock::now();
	sort(arr2, arr2 + SIZE2);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to sort array of size 10 million: " << duration.count() << " microseconds" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl << endl;
	
	//Create linked lists from the sorted arrays
	start = high_resolution_clock::now();
	Node *head1 = arrayToList(arr1, SIZE1);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to create Linked Lists from sorted array of size 1 million: " << duration.count() << " microseconds" << endl;
	
	start = high_resolution_clock::now();
	Node *head2 = arrayToList(arr2, SIZE2);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to create Linked Lists from sorted array of size 10 million: " << duration.count() << " microseconds" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl << endl;
	
	//test recursive search method and display time it took to execute
	//arbitrary value of 12345 used as desired value to be searched
	cout << "Recursive Binary Search of value: 12345" << endl;
	start = high_resolution_clock::now();
	int arr1Index = recursive(arr1, 0, SIZE1, VAL);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<microseconds>(stop - start);
	cout << "Value found at index: " << arr1Index << endl;
	cout << "Time it took to perform a recursive binary search of size 1 million: " << duration.count() << " microseconds" << endl;
	
	start = high_resolution_clock::now();
	int arr2Index = recursive(arr2, 0, SIZE2, VAL);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<microseconds>(stop - start);
	cout << "Value found at index: " << arr2Index << endl;
	cout << "Time it took to perform a recursive binary search of size 10 million: " << duration.count() << " microseconds" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl << endl;
	
	//test iterative search method
	//arbitrary value of 12345 used as desired value to be searched
	cout << "Iterative Binary Search of value: 12345" << endl;
	start = high_resolution_clock::now();
	arr1Index = iterative(arr1, 0, SIZE1, VAL);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<microseconds>(stop - start);
	cout << "Value found at index: " << arr1Index << endl;
	cout << "Time it took to perform an iterative binary search of size 1 million: " << duration.count() << " microseconds" << endl;
	
	start = high_resolution_clock::now();
	arr2Index = iterative(arr2, 0, SIZE2, VAL);
	stop = high_resolution_clock::now(); 
	duration = duration_cast<microseconds>(stop - start);
	cout << "Value found at index: " << arr2Index << endl;
	cout << "Time it took to perform an iterative binary search of size 10 million: " << duration.count() << " microseconds" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl << endl;
	
	//test linked list search method
	cout << "Binary Search using a Linked List of value: 12345" << endl;
	start = high_resolution_clock::now();
	if (linkedBinary(head1, VAL) == NULL) 
        cout << "Value not found" << endl; 
    else
        cout << "Value found" << endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to perform a linked list type binary search of size 1 million: " << duration.count() << " microseconds" << endl;
	
	start = high_resolution_clock::now();
	if (linkedBinary(head2, VAL) == NULL) 
        cout << "Value not found" << endl; 
    else
        cout << "Value found" << endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to perform a linked list type binary search of size 10 million: " << duration.count() << " microseconds" << endl;
	
	//clean memory
	delete [] arr1;
	delete [] arr2;
	
	return 0;
}
