// CS313 HW 1 Program 1 Vector
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v1; // creating a vector v1

    for (int i = 1; i <= 5; i++){ // assigning the vector with 1,2,3,4,5
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

    // clear the vector

    v1.clear();
    cout << endl;

   // filling the vector with random number from 1 to 20

   cout <<"Random Number Vector (1 to 20): ";
   srand ((unsigned)time(NULL));
   int a = rand() % 20 + 1;
   for (int i = 0; i < a; i++){
       int b  = rand() % 20 + 1;
       v1.push_back(b);
       cout << v1[i] << " ";
   } 
}
