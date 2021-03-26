 /*
	@Suyogya Rayamajhi
	@CSCI-313
	@Group 6
	@Date: 3/21/21
    Homework 1 Program 11 
    Create a class called Restaurant. Give it the necessary structure, variables, and functions, 
    and create a pure virtual function called menu. 
    Create a class called Italian_Restaurant, Greek_Restaurant, and Chinese_Restaurant as derived classes. 
    Use the parent classes constructor as well as any other variables that need to be created. 
    Create a templated class called Reader_Robot. It should take in ​any​ kind of restaurant and use polymorphism to 
    read the menu (that you overrode). Show how this works in main.
*/
#include <iostream>

using namespace std;

class Restaurant
{
    public:
    string Name; // class variable
    void printName() // member function
    {
        cout <<"Restaurant name is: "<<Name<<endl;
    }
 
    virtual void menu() = 0; // pure virtual function
    
};

struct Derived:Restaurant // struct derived from class Restaurant
{

};

// derived classes

class Italian_Restaurant: public Restaurant
{
    public:
    void menu() { cout << "Italian restaurant menu \n"; }
   //string menuItem = "Calzone";
};

class Greek_Restaurant: public Restaurant
{
    public:
    void menu() { cout << "Greek restaurant menu \n"; }
    //string menuItem = "Gyro";
};

class Chinese_Restaurant: public Restaurant
{
    public:
    void menu() { cout << "Chinese restaurant menu \n"; }
    //string menuItem = "Chow Mein";
};

// creating a templated class
template <class T>
class Reader_Robot: public Restaurant
{
    T a;
    public:
    Reader_Robot(T menuName){ a = menuName;}
    T getMenu ();
};

template <class T>
T Reader_Robot <T>::getMenu()
{
    return menu();
}

int main()
{
    Restaurant * bp = new Italian_Restaurant();
    bp -> menu();
    

    Reader_Robot <string> myObject (Chinese_Restaurant);
    //myObject.getMenu();
    return 0;

}

