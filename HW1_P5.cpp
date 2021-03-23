/*
	@Ahmed Fathalla
	@CSCI-313
	@Group 6
	@Date: 3/23/21
*/
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using namespace std;

const int SIZE = 10000;
int callStack = 0;
void Display(int arr[], int size);
void FillArr(int arr[]);
void InsertionSort(int arr[], int size);
void mergeSort(int a[], int tmpArray[], int left, int right);
void merge(int a[], int tmpArray[], int leftPos, int rightPos, int rightEnd);
template <typename Func>
long long TimeFunc(Func f);

//https://www.programiz.com/cpp-programming/library-function/cstdlib/qsort#:~:text=The%20qsort()%20function%20in,smaller%2Fgreater%20than%20the%20other.
int compare(const void* a, const void* b){
	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int main() {
	srand(time(nullptr));
	int arr[SIZE];
	int arrTwo[SIZE];
	int arrThree[SIZE];
	int temp[SIZE];

	FillArr(arr);
	FillArr(arrTwo);
	FillArr(arrThree);
	//Display(arr, SIZE);

	cout<<endl;
	auto arrayMilliseconds = TimeFunc([&]() {mergeSort(arr, temp, 0, SIZE - 1); });
	auto arrayTwoMilliseconds = TimeFunc([&]() {sort(arrTwo, arrTwo+SIZE); });
	auto arrayThreeMilliseconds = TimeFunc([&]() {qsort(arrThree,SIZE, sizeof(int), compare); });

	cout << "\nTime it took (in milliseconds) to sort an array with random numbers of size 10000 using Mergesort/Insertionsort: " << arrayMilliseconds << endl;
	cout << "\nTime it took (in milliseconds) to sort an array with random numbers of size 10000 using algorithm library sort: " << arrayTwoMilliseconds << endl;
	cout << "\nTime it took (in milliseconds) to sort an array with random numbers of size 10000 using algorithm library qsort: " << arrayThreeMilliseconds << endl;
	//Display(arrThree, SIZE);

	return 0;
}
//Assigns random numbers to the array.
void FillArr(int arr[]) {
	
	for (int i = 0; i < SIZE; i++)
	{
		*(arr + i) = rand() % SIZE + 1;
	}
}

//Displays array elements
void Display(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << "\t";
	}
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

//Sorts the array by comparing adjacent elements and repeating the process n times.
void InsertionSort(int arr[], int size)
{
	// Iterate to all array's element
	for (int i = callStack; i < size; ++i)
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
//Sorts an array using a divide&conquer algorithm.It breaks the array in half until we deal with
//one element and repeats this process recursively.
void mergeSort(int a[], int tmpArray[], int left, int right){
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort(a, tmpArray, left, center);
		mergeSort(a, tmpArray, center + 1, right);
		merge(a, tmpArray, left, center + 1, right);
	}
}

void merge(int a[],int tmpArray[],int leftPos, int rightPos, int rightEnd)
{
	//To sort elements of size 10 
	callStack++;
	if (callStack == SIZE -10) {
		InsertionSort(a,SIZE);
	}
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	// Main loop
	while (leftPos <= leftEnd && rightPos <= rightEnd)
		if (a[leftPos] <= a[rightPos])
			tmpArray[tmpPos++] = std::move(a[leftPos++]);
		else
			tmpArray[tmpPos++] = std::move(a[rightPos++]);

	while (leftPos <= leftEnd)    // Copy rest of first half
		tmpArray[tmpPos++] = std::move(a[leftPos++]);

	while (rightPos <= rightEnd)  // Copy rest of right half
		tmpArray[tmpPos++] = std::move(a[rightPos++]);

	// Copy tmpArray back
	for (int i = 0; i < numElements; ++i, --rightEnd)
		a[rightEnd] = std::move(tmpArray[rightEnd]);
}
