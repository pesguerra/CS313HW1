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
#include <list>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
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
void insert(Node** root, int item)
{
    Node* temp = new Node;
    Node* ptr;
    temp->data = item;
    temp->next = NULL;
  
    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

//function to fill a Linked List with values from an array passed through the parameter
Node *arrayToList(int arr[], int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, arr[i]);
   return root;
}

//function to find the middle element of the passed Linked List
Node* middle(Node* start, Node* last) 
{ 
    if (start == NULL) 
        return NULL; 
  
    Node* slow = start; 
    Node* fast = start -> next; 
  
    while (fast != last) 
    { 
        fast = fast -> next; 
        if (fast != last) 
        { 
            slow = slow -> next; 
            fast = fast -> next; 
        } 
    } 
  
    return slow; 
}

//function to implement a binary search using the Linked List data structure 
Node* linkedBinary(Node *head, int value) 
{ 
    Node* start = head; 
    Node* last = NULL; 
  
    do
    { 
        // Find middle 
        Node* mid = middle(start, last); 
  
        // If middle is empty 
        if (mid == NULL) 
            return NULL; 
  
        // If value is present at middle 
        if (mid -> data == value) 
            return mid; 
  
        // If value is more than mid 
        else if (mid -> data < value) 
            start = mid -> next; 
  
        // If the value is less than mid. 
        else
            last = mid; 
  
    } while (last == NULL || (last != start)); 
  
    // value not present 
    return NULL; 
} 

//function to implement a recursive binary search
//output is the index at which the desired int x is found or -1 which indicates not found inside passed array
int recursive(int arr[], int l, int r, int x) {	
	if (r >= l) { 
        int mid = l+(r-l) / 2; 
        if (arr[mid] == x) {
            return mid;
        }
		if (arr[mid] < x) {
        	return recursive(arr, mid+1, r, x); 
		}
        return recursive(arr, l, mid-1, x);
    } 
    return -1;
}

//function to implement an iterative binary search
//output is the index at which the desired int x is found or -1 which indicates not found inside passed array
int iterative(int arr[], int l, int r, int x) {
	while (l <= r) { 
        int mid = l+(r-l) / 2; 
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
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
	int const SIZE1 = 100000;
	int const SIZE2 = 100000;
	//arbitrary int value to search for
	int const VAL = 12345;
	
	//Declare arrays of sizes 1 million and 10 million on heap
	int arr1[SIZE1];
	int arr2[SIZE2];
	
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
	Node *head2 = arrayToList(arr2, SIZE2);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to create Linked Lists from sorted arrays: " << duration.count() << " microseconds" << endl;
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
        cout << "Value not present" << endl; 
    else
        cout << "Value found" << endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to perform a linked list type binary search of size 1 million: " << duration.count() << " microseconds" << endl;
	
	start = high_resolution_clock::now();
	if (linkedBinary(head2, VAL) == NULL) 
        cout << "Value not present" << endl; 
    else
        cout << "Value found" << endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to perform a linked list type binary search of size 10 million: " << duration.count() << " microseconds" << endl;
	
	return 0;
}
