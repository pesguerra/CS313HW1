/*
	@Suyogya Rayamajhi
	@CSCI-313
	@Group 6
	@Date: 3/21/21
    Homework 1 Program 12 
    Create a doubly Linked List that does insertion and deletion in the correct position. 
    Alice is an office manager. She uses her doubly Linked List to insert appointments in the proper position. 
    A new list is created each week to hold appointments from Monday to Friday, 9am-5pm. 
    Each appointment can be anywhere from 30min to 2hrs. Alice schedules all appointments the week prior. 
    Her rule is that if a user asks for an appointment slot that is taken, 
    she will find you the closest available one (on her doubly Linked List - 
    which may mean that a Friday appointment will be scheduled on a Monday). 
    Show with ample explanation how Alice fills in the appointments for the week
*/
#include<iostream>
using namespace std;

int size;	// number of nodes or appointments to be crated

struct Node	// node structure declaration for each appointment
{
    int start;
    int end;
    int min;
    int max;
    int flag;
    struct Node *next;
}*head;


class App_Schedule
{
  public:
	void create_Shed();
         	 
	void display_Shed();

	void book_App();

	void cancel_App();

	//void sort_App();
	
}A1;


int main()
{
   int choice;
   char ans;
   
   do
   {    
      cout<<"\n 1. Create New Appointment Schedule ";
      cout<<"\n 2. Display Free Appointment Slots";
      cout<<"\n 3. Book an Appointment";
      cout<<"\n 4. Cancel an Appointment";
     
      cout<<"\n Enter your choice in number: ";                        
      cin>>choice;
      
      switch(choice)
      {
         case 1: A1.create_Shed();
         	 break;
         	 
         case 2: A1.display_Shed();
         	 break;         	 
         	 
         case 3: A1.book_App();
         	 break;
         	 
         case 4: A1.cancel_App();
         	 break;

         default: cout<<"Invalid Choice";
	          	 
      }
      cout<<"\n Do you wanna continue? (y/n) : ";
      cin>>ans;
   } while (ans == 'y'); 
}

void App_Schedule :: create_Shed() //Function Definition to create Appointment Schedule
{
    int i;
    struct Node *temp, *last;
    
    head = NULL;
    
    cout<<"\n How many Appointment Slots: ";
    cin>>size;
    
    for(i = 0; i < size; i++)
    {
       temp = new(struct Node); // Dynamic Memory Allocation
       
       cout<<"\nEnter Start Time ((9am to 5pm) if '10am' enter 10): ";   // Assigning Data & Address
       cin>>temp->start; 
       cout<<"\nEnter End Time ((9am to 5pm) if '3pm' enter 3): ";
       cin>>temp->end;
       cout<<"\nEnter Minimum Appointment Duration in minutes (Min Time = 30 minutes): ";
       cin>>temp->min;
       cout<<"\n Enter Maximum Appointment Duration in minutes (Max Time = 120 minutes): ";
       cin>>temp->max;
       temp->flag = 0;
       temp->next = NULL;
       
       if(head == NULL)
       {
          head = temp;
          last = head;
       }
       else
       {
          last->next = temp;
          last = last->next;
       }
       
    }
}

void App_Schedule :: display_Shed()   //Function Definition to Display the Appointment Schedule         
{
   int count = 1;
   struct Node *temp;
   
   cout<<"Appointment Schedule is as follows\n";
   cout<<"\n\tSrNo.\tStart\tEnd\tMin_Dur\tMax_Dur\tStatus";        
   
   temp = head;
   while(temp != NULL)
   {
      cout<<"\n\t "<<count;
      cout<<"\t "<<temp->start;
      cout<<"\t "<<temp->end;
      cout<<"\t  "<<temp->min;
      cout<<"\t  "<<temp->max;
      
      if(temp->flag)
         cout<<"\t-Booked-";                        
      else
         cout<<"\t-Free-";         
         
      temp = temp->next; 
      count++;  
   }
}

void App_Schedule :: book_App() //Function Definition to Book Appointment
{
    int start;
    struct Node *temp;

    cout<<"\n Please enter Appointment Start time: ";
    cin>>start;
 
   temp = head;

   while(temp != NULL)
   {
      if(start == temp->start)
      {
         if(temp->flag == 0)
         {
            cout<<"\n Appointment Slot is Booked!";
            temp->flag = 1;
         }
         else
            cout<<"\n Appointment Slot is not Available!";
      }

      temp = temp->next; 
   }

}
      
void App_Schedule :: cancel_App() //Function Definition to Cancel Appointment
{
    int start;
    struct Node *temp;

    cout<<"\n Please enter Appointment Start time to Cancel: ";
    cin>>start;
 
   temp = head;

   while(temp != NULL)
   {
      if(start == temp->start)
      {
         if(temp->flag == 1)
         {
            cout<<"\n Your Appointment slot has been canceled!!!";
            temp->flag = 0;
         }
         else
            cout<<"\n\n\t Your Appointment was NOT Booked!!!";
      }

      temp = temp->next; 
   }
}

