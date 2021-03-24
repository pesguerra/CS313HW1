/*
	@Suyogya Rayamajhi
	@CSCI-313
	@Group 6
	@Date: 3/21/21
    Homework 1 Program 7
    C++ program that compares 3 seperate containers
*/

#include <algorithm> 
#include <chrono> 
#include <iostream> 
#include <vector> 
#include <time.h>
#include <list>

using namespace std; 
using namespace std::chrono; 

class node // node declaration 
{
    public:
        int data;
        node* next;
};

node* BuildListForward(int size);

int main() 
{ 
    int const size = 10000;
	vector<int> values(size); // Dynamic array declaration

	// random value genrator
	auto f = []() -> int { return rand() % size; }; 

	// start time point
	auto start = high_resolution_clock::now();

    // filling the vector
	generate(values.begin(), values.end(), f); 
    
    // getting end timepoint 
	auto stop = high_resolution_clock::now(); 

    // getting duration by getting the difference between start time 
    // and stop time 
	auto duration = duration_cast<microseconds>(stop - start); 

	cout << "Time taken to fill Vector with 10000 random numbers: "
	<< duration.count() << " microseconds" << endl; 
    
    // Array section
    srand(time(nullptr));

	int arrOne[size];
	int arrTwo[size];

	// assigning random numbers to the array.
    auto startArray = high_resolution_clock::now();

    // filling that array with 10000 random numbers
	for (int i = 0; i < size; i++)
	{
		*(arrOne + i) = rand() % size + 1;
		*(arrTwo + i) = rand() % size + 1;

	}

    auto stopArray = high_resolution_clock::now(); 

    // getting time taken by array to fill up with 10000 random numbers
    auto durationArray = duration_cast<microseconds>(stopArray - startArray);

    cout << "Time taken to fill an Array with 10000 random numbers: "
    << durationArray.count()<<" microseconds"<<endl;

    //List section

    auto startList = high_resolution_clock::now();

    node* listOne = BuildListForward(size);

    auto stopList = high_resolution_clock::now(); 

    auto durationList = duration_cast<microseconds>(stopList - startList);

    cout << "Time taken to fill a List with 10000 random numbers: "<< 
    durationList.count()<<" microseconds"<<endl;

	return 0; 
} 

// Function that builds the list of size 10000 and fills it 
// with random numbers
node* BuildListForward(int size) {
	node* first, * last, * newNode;

	first = last = nullptr;

	for (int i = 0; i < size; i++) {

		newNode = new node;
		newNode->data = rand() % size + 1;
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
