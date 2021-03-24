/*
*	@Paolo Esguerra
*	@CSCI-313
*	@Group 6
*	@Date: 3/24/21
*	HW 1 Program 8
*	Create a templated class that effectively finds all possibilities of a list of random numbers that add to some s.
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;
  
// The vector v stores current subset.
void printAllSubsetsRec(int arr[], int n, vector<int> v,
                        int sum)
{
    // If remaining sum is 0, then print all
    // elements of current subset.
    if (sum == 0) {
    	cout << "[ ";
        for (auto x : v)
            cout << x << " ";
        cout << "]" << endl;
        return;
    }
  
    // If no remaining elements,
    if (n == 0)
        return;
  
    // We consider two cases for every element.
    // a) We do not include last element.
    // b) We include last element in current subset.
    printAllSubsetsRec(arr, n - 1, v, sum);
    v.push_back(arr[n - 1]);
    printAllSubsetsRec(arr, n - 1, v, sum - arr[n - 1]);
}
  
// Wrapper over printAllSubsetsRec()
void printAllSubsets(int arr[], int n, int sum)
{
    vector<int> v;
    printAllSubsetsRec(arr, n, v, sum);
}
  
int main()
{
    //declare necessary variables
	int size, val;
	srand(time(nullptr));
	
	//get user input for the size of array
	cout << "Enter an integer for the size of the array:" << endl;
	cin >> size;
	
	//take user input and create array using the value
	int arr[size];
	
	//fill the array with random values using rand() and display the values
	cout << "[";
	for(int i=0; i<size; i++) {
		*(arr + i) = rand() % size + 1;
		if(i == size-1)
			cout << *(arr + i) << "]" << endl;
		else
			cout << *(arr + i) << ", ";
	}
	
	//get user input for the targeted value being searched
	cout << "Enter a value to find the subset sum of: " << endl;
	cin >> val;
    printAllSubsets(arr, size, val);
    return 0;
}
