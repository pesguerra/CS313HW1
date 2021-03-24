/*
	@Suyogya Rayamajhi
	@CSCI-313
	@Group 6
	@Date: 3/21/21
    Homework 1 Program 1
    C++ Linked List
*/

#include <iostream>
#include <list>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono; 

class Node{
    public: int data;
    Node* next;
};

// Node insertion function definition
void push(Node** head_ref, int new_data){

    Node* new_node = new Node(); // new node allocation

    new_node -> data = new_data; // putting data in the new node

    new_node -> next = (*head_ref); // making next of new node as the head

    (*head_ref) = new_node;
}
// Print node function definition
void printList(Node *node){
    while (node != NULL){
        cout <<" "<<node->data;
        node = node->next;
    }
}

// list 2 function definition
void print(list<string> const &list)
{
    for (auto const& i: list) {
        std::cout << i << "\n";
    }
}

// Node deletion function definition
void deleteNode(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // chaning the head
        delete temp;            // freeing the previous head
        return;
    }
 
    // Else we Search for the key to be deleted,
    // keep track of the previous node as we need to change 'prev->next'
    else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key is not present in linked list
    if (temp == NULL)
        return;
 
    // Unlinking the node from linked list
    prev->next = temp->next;
 
    // Freeing the memory
    delete temp;
    }
}

int main (){
    // creating simple linked list with 3 nodes
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // dynamically allocating 3 nodes in heap
    head  = new Node();
    second  = new Node();
    third  = new Node();

    // data assignment
    head -> data = 1;

    // linking the first node with the second node
    head -> next = second;

    // similarly for the second node
    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = NULL; // end of linked list

    // printing the newly created list
    cout <<"New Linked List: ";
    printList(head);
    cout <<endl;
    // inserting a new node in the beginning
    
    push(&head, 5); // insertion function call
    
    cout <<"List after insertion in the front: ";
    printList(head); // printing again

    cout <<endl;

    deleteNode(&head, 1);
    cout <<"List after deletion of 1: ";
    printList(head); // printing again
    
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 1000; i++)
    {
        int random = rand() % 100;

        Node* newNode = new Node;
        newNode->data = random;
        push(&head, random);
    }   
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); // calculating the time difference

    cout << endl;

    cout << "Time taken to fill the list with 1000 random numbers: "
	<< duration.count() << " microseconds" << endl; 

    cout <<endl;
    //cout <<"List after 20 random number insertion: ";
    //printList(head);
    
    cout <<endl;
    
    list <string> mylist;
    string str;
    char c;

    auto startlist2 = high_resolution_clock::now(); 
    for (int i = 0; i < 100; i++)
    {
      for (int j = 0; j < 5; j++)
      {
          c = rand () % 26 + 'A';
          str += c;
      }
    mylist.push_back(str);
    str.clear();
  }
   auto stoplist2 = high_resolution_clock::now();
   auto duration2 = duration_cast<microseconds>(stoplist2 - startlist2); // calculating the time difference

   cout << endl;

    cout << "Time taken to fill the list with 100 random strings of size 5: "
	<< duration2.count() << " microseconds" << endl;
  //cout <<"List after 10 random strings insertion: ";
  //print(mylist);
    
}
