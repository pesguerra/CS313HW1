/*
*	@Paolo Esguerra
*	@CSCI-313
*	@Group 6
*	@Date: 3/25/21
*	HW 1 Program 9
*	Create a structure filled with random 0s and 1s of size t
*	Create a function to check if it is a deBruijn sequence of B(2,k). 
*	If your random array is not a deBruijin sequence, randomly mutate each spot in the array
*	(from a 0 to 1 or 1 to 0) with a 5% probability, keep doing this until you have found a deBruijn sequence.
*	Do this with an array structure and a linked structure. Do this 100 times for each, time it, and compare your results 
*/

#include <iostream>
#include <chrono>
#include <algorithm>
#include <math.h>

using namespace std::chrono;
using namespace std;

//Node class declaration
class Node {
public:
	int data;
	Node* next;
};

//Builds a linked list and assigns random numbers from 0 to 1. Utilized Suyogya's function
Node* BuildListForward(int size) {
	Node* first, * last, * newNode;

	first = last = nullptr;

	for (int i = 0; i < size; i++) {

		newNode = new Node;
		newNode->data = rand() % 2;;
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

//function to determine whether or not the passed array sequence is a deBruijin sequence
//unfinished returns true for now to debug rest of program
bool isDeBruijin(int arr[]) {
	return true;
}

//function to mutaute integer value which should be a 0 or 1 with a 5% probability
int mutate(int val) {
	//generate a random number and if it is divisible by 20 then mutate
	int randNum = (rand() % 100) + 1;
	if(randNum%20 == 0) {
		if(val == 0)
			return 1;
		else
			return 0;
	}
	//otherwise return same value
	else {
		return val;
	}
}


int main() {
	srand(time(nullptr));
	int input, size;
	
	//get user input
	cout << "Enter an integer for the degree k in a binary DeBruijin sequence: " << endl;
	cin >> input;
	//instantiate size with 2 to the power of the user input
	size = (int)pow(2,input);
	
	//Start clock to find time at which 100 arrays are mutated to be DeBruijin sequences
	auto start = high_resolution_clock::now();
	
	//create an array of size 2^k because that is the length necessary for a binary Debruijin sequence
	int *arr = new int[size];
	for(int i=0; i<100; i++) {
		//fill array with random 0s or 1s
		for(int i=0; i<size; i++) {
			*(arr + i) = rand() % 2;
			cout << arr[i] << " ";
		}
		cout << endl << endl;
	
		//loop through array and determine whether it is a DeBruijin sequence, if not then mutate intil it is
		while(!isDeBruijin(arr)) {
			//arr[i] = mutate(arr[i]);
		}
	}
	
	
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to mutate and find 100 binary DeBruijin sequences of degree " << input << " with an array structure: " << duration.count() << " microseconds" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl << endl;
	
	//Start clock to find time at which 100 linked lists are mutated to be DeBruijin sequences
	start = high_resolution_clock::now();
	
	for(int j=0; j<100; j++) {
		//create a linked list using user inputted size
		Node* list = BuildListForward(size);
	
		//Prints list for debugging purposes
		while (list != nullptr) {
			cout << list->data << " ";
			list = list->next;
		}
		cout << endl << endl;
		
		//function to determine if a linked list is a DeBruijin sequence and mutate if not
	}

	stop = high_resolution_clock::now(); 
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time it took to mutate and find 100 binary DeBruijin sequences of degree " << input << " with a linked list structure: " << duration.count() << " microseconds" << endl;
	
	return 0;
}
