/*
	@Suyogya Rayamajhi
	@CSCI-313
	@Group 6
	@Date: 3/21/21
    Homework 1 Program 1
    C++ Vector & Linked List with Move Semantics
*/

#include <iostream>
#include <list>
#include <vector>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono; 

// function that gets random strings
string getRandomString(int length) {
	int flag;
	char* ch = new char[length] ;
	for (int i = 0; i < length - 1; i++) {
		flag = rand() % 3;
		switch (flag)
		{
			case 0:
				ch[i] = rand() % 26 + 'A';
				break;

			case 1:
				ch[i] = rand() % 26 + 'a';
				break;

		default:
			ch[i] = rand() % 10 + '0';
			break;
		}
	}
	ch[length - 1] = '\0';
	string str = ch;
	return str;
}

//function that takes int size and vector and fills them with random strings
void VectorOfRandomStrings_Move(int size, vector<string> v) 
{
	for (int i = 0; i < size; i++) 
    {
		int length = rand() % 50 + 1;
		string str = getRandomString(length);
		v.push_back(move(str));

	}
}

//function that takes int size and list and fills them with random strings
void ListOfRandomString_Move(int size, list<string> l) 
{
	for (int i = 0; i < size; i++) 
    {
		int length = rand() % 50 + 1;
		string str = getRandomString(length);
		l.push_back(move(str));
	}
}

int main()
{   int const size = 10000;

    cout << "Program 1 with move semantics:" << endl;
    vector <string> v3;
    list <string> l3;
	
    auto start = high_resolution_clock::now();
    VectorOfRandomStrings_Move(size, v3); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); // calculating the time difference
    
    cout << endl;
    cout << "Time taken to fill Vector with 10000 random strings with move semantics: "
	<< duration.count() << " microseconds" << endl; 
	
    auto startString = high_resolution_clock::now();
    ListOfRandomString_Move(size, l3);
    auto stopString = high_resolution_clock::now();
    auto durationString = duration_cast<microseconds>(stopString - startString); 
    cout<< endl;
    cout << "Time taken to fill List with 0000 random strings with move semantics: "
    << durationString.count() << " microseconds" << endl; 

}
