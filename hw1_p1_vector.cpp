/*
	@Suyogya Rayamajhi
	@CSCI-313
	@Group 6
	@Date: 3/21/21
    Homework 1 Program 1
    C++ Vector
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono; 

int main()
{
    vector <int> v1; // creating a vector v1
    
    for (int i = 1; i <= 5; i++)
    { // assigning the vector with 1,2,3,4,5
        v1.push_back(i);
    }

    // prints the newly created vector
    cout << "Vector V1: ";
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    
    // vector insertion at the beginning
    v1.insert(v1.begin(), 6);

    cout << "New Vector with 6 inserted at the beginning: ";
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    } 
    cout << endl;
    
    // vector deletion of the last element
    v1.pop_back();

    cout << "New Vector with last element deleted: ";
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    } 
    cout << endl;

    // vector search
    cout <<"Vector Search. ";
    if (find(v1.begin(), v1.end(), 3) != v1.end())
        cout <<"Item found";
    else
        cout <<"Item NOT found";
    
    v1.clear(); // clear the vector
    cout << endl;

   // filling the vector with random number from 1 to 20

   //cout <<"Random Number Vector (1 to 20): ";
   auto start = high_resolution_clock::now(); // making note of time to calculate the time required to perform the function
   
   srand ((unsigned)time(NULL));
   for (int i = 0; i < 1000; i++)
   {
       int b  = rand() % 100;
       v1.push_back(b);
   }

   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start); // calculating the time difference

   cout << endl;

    cout << "Time taken to fill Vector with 1000 random numbers: "
	<< duration.count() << " microseconds" << endl; 

    v1.clear(); // clear the vector
    cout << endl;
  
  // filling a vector with random string
  
  vector <string> vec;
  string str;
  char c;

  auto startString = high_resolution_clock::now();

  for (int i = 0; i < 100; i++)
  {
      for (int j = 0; j < 5; j++)
      {
          c = rand () % 26 + 'A';
          str += c;
      }
    vec.push_back(str);
    str.clear();
  }
    
    auto stopString = high_resolution_clock::now();
    auto durationString = duration_cast<microseconds>(stopString - startString); 
    cout<< endl;
    cout << "Time taken to fill Vector with 100 random strings of size 5: "
    << durationString.count() << " microseconds" << endl; 

}
