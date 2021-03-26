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
#include <vector>
using namespace std;

//templated class to find all subsets of array that will sum any given int passed and print it
template <class T>
void printAllSubsets(T arr[], T size, vector<T> v, T sum) {
    // If remaining sum is 0, then print all
    // elements of current subset.
    if (sum == 0) {
    	cout << "[ ";
        for (auto x : v)
            cout << x << " ";
        cout << "]" << endl;
        return;
    }
  
    // Base Case of no more elements remaining
    if (size == 0)
        return;
  
    //2 recursion calls because there are 2 cases for every element
	//a case for including the last element and a case not including the last element 
	//when the case calls for the last element to be included it is pushed to the vector v and the targeted sum is decreased
    printAllSubsets(arr, size - 1, v, sum);
    v.push_back(arr[size - 1]);
    printAllSubsets(arr, size - 1, v, sum - arr[size - 1]);
}

int main()
{
	//declare necessary variables
	int size, val;
	vector<int> v;
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
	
    printAllSubsets<int>(arr, size, v, val);

    return 0;
}
