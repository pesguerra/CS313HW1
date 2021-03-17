/*
	@Ahmed Fathalla
	@CSCI-313
	@Group 6
	@Date: 3/16/21
*/

#include <iostream>
#include <chrono>
#include <time.h>
#include <vector>
#include <list>

class node {
public:
	int data;
	node* next;
};

using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using namespace std;

void InsertionSort(int arr[], int size);
void BubbleSort(int arr[], int size);
void Display(int arr[], int size);

void InsertionSort(node* newNode);
void PrintList(node* val);
node* BuildListForward(int size);
void BubbleSort(node* head);

template <typename Func>
long long TimeFunc(Func f);

int main()
{
	int const size = 10'000;
	srand(time(nullptr));

	int arrOne[size];
	int arrTwo[size];

	//Assigns random numbers to the array.
	for (int i = 0; i < size; i++)
	{
		*(arrOne + i) = rand() % size + 1;
		*(arrTwo + i) = rand() % size + 1;

	}

	auto arrayMilliseconds = TimeFunc([&]() {InsertionSort(arrOne, size); });
	cout << "\nTime it took (in milliseconds) to sort array of size 10000 using Insertion sort: " << arrayMilliseconds << endl;
	//Display(arrOne, size);

	arrayMilliseconds = TimeFunc([&]() {BubbleSort(arrTwo, size); });
	cout << "\nTime it took (in milliseconds) to sort array of size 10000 using Bubble sort: " << arrayMilliseconds << endl;
	//Display(arrTwo, size);

	//Insert random numbers into listOne.
	node* listOne = BuildListForward(size);
	node* listTwo = BuildListForward(size);
	
	auto listmilliseconds = TimeFunc([&]() {InsertionSort(listOne); });
	//PrintList(listOne); 
	cout << "\nTime it took (in milliseconds) to sort list of size 10000 using Insertion sort: " << listmilliseconds << endl;

	listmilliseconds = TimeFunc([&]() {BubbleSort(listTwo); });
	//PrintList(listTwo);
	cout << "\nTime it took (in milliseconds) to sort list of size 10000 using Bubble sort: " << listmilliseconds << endl;

}

//Returns time in milliseconds
template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}

//Displays array elements
void Display(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << "\t";
	}
}

//Sorts a linkedlist using 2 pointers
void InsertionSort(node* curr)
{
	//curr & ptr are pointing to the head 
	node* head = curr;
	node* ptr = head;

	curr = curr->next;
	while (curr != nullptr) {

		ptr = head;

		while (ptr != curr) {
			if (ptr->data > curr->data) {
				swap(ptr->data , curr->data);
			}
			else{
				ptr = ptr->next;
			}
		}
		curr = curr->next;

	}
}

// Sorts an array from left to right (In-place algorithm) by
// splitting the array to a unsorted and sorted partitions.
void InsertionSort(int arr[], int size)
{
	// Iterate to all array's element
	for (int i = 0; i < size; ++i)
	{
		// Set the current element
		// as reference value
		int refValue = arr[i];

		// variable to shift the element
		// to right position
		int j;

		// Iterate through the sorted element
		// to insert the reference value
		// in right position
		for (j = i - 1; j >= 0; --j)
		{
			// if the value of the current index
			// is greater than the reference value then
			// move the current value to right side
			// otherwise, put the reference value
			// in the current index
			if (arr[j] > refValue)
				arr[j + 1] = arr[j];
			else
				break;
		}

		// here's the line to put the reference value
		// in the current index (the right position)
		arr[j + 1] = refValue;
	}
}

//Sorts the array by comparing adjacent elements and repeating the process n times.
void BubbleSort(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			//Compares adjacent elements and swaps if one element is 
			//greater than its next element
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//Sorts the array by comparing a node and node->next and repeating the process as long as 
//head->next is not null.
void BubbleSort(node* head) {

	node* curr, * ptr;
	ptr = head;
	curr = head->next;

	for (curr = head; curr != nullptr;curr=curr->next) {
		for (ptr = curr->next; ptr!=nullptr; ptr=ptr->next)
		{
			if (curr->data > ptr->data) {
				swap(curr->data , ptr->data);
			}
		}
	}
}

//Builds a list and assigns random numbers.
node* BuildListForward(int size) {
	node* first, * last, * newNode;

	first = last = nullptr;

	for (int i = 0; i < size; i++) {

		newNode = new node;
		newNode->data = rand() % size + 1;;
		newNode->next = nullptr;

		if (first == nullptr) {
			first = last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
	}
	return first;
}

//Prints a list and stops when current is null.
void PrintList(node* val) {
	node* current = val;

	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl << endl;
}
