#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
/*
	@Ahmed Fathalla
	@CSCI-313
	@Group 6
	@Date: 3/11/21
*/
/*
	1.Create a 2D array.
	2.Get user input for values.
	3.Iterate through the rows and columns
	4.Fill in the array with user input.
	5.Use all three sorts to sort the array in an ascending order.
*/

const int ROWS = 3;
const int COLUMNS = 3;

void display(int arr[ROWS][COLUMNS]);
void fill(int arr[ROWS][COLUMNS]);
void SelectionSort(int arr[ROWS][COLUMNS], int arrSize);
void InsertionSort(int arr[ROWS][COLUMNS], int arrSize);
void bubbleSort(int arr[ROWS][COLUMNS], int arrSize);

int main() {
    srand(time(nullptr));
    cout << "===================" << endl;
    cout << "Selection sort" << endl;
    cout << "===================" << endl;
    cout << "Enter values for the matrix" << endl;
    int arr[ROWS][COLUMNS];
    fill(arr);
    display(arr);

    cout << "Sorted" << endl;

    //Loops 9 times to fully sort the 2D matrix.
    for (int i = 0; i < 9; i++)
    {
        SelectionSort(arr, 9);
    }

    display(arr);

    cout << "===================" << endl;
    cout << "Insertion sort" << endl;
    cout << "===================" << endl;
    cout << "Enter values for the matrix" << endl;
    int arrTwo[ROWS][COLUMNS];
    fill(arrTwo);
    display(arrTwo);
    cout << "Sorted" << endl;
    InsertionSort(arrTwo, 9);
    display(arrTwo);

    cout << "===================" << endl;
    cout << "Bubble sort" << endl;
    cout << "===================" << endl;
    cout << "Enter values for the matrix" << endl;
    int arrThree[ROWS][COLUMNS];
    fill(arrThree);
    display(arrThree);
    cout << "Sorted" << endl;
    bubbleSort(arrThree, 9);
    display(arrThree);

    return 0;
}

//Fills the matrix with random elements
void fill(int arr[ROWS][COLUMNS]) {
    int size = 100;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++) {
           arr[i][j] = rand() % size + 1;;
           
		}
	}
    cout << endl;
}
//Displays elements in 2D matrix.
void display(int arr[ROWS][COLUMNS]) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < COLUMNS; j++) {
			//cout << "i: " << i << " j: " << j << " matrix[i][j]: " << arr[i][j] << endl;
            cout<< arr[i][j] << "\t";

		}
        cout << endl;
	}
}

void SelectionSort(int arr[ROWS][COLUMNS], int arrSize)
{
    // variable to store the index of the minimum value
    // in each iteration
    int minIndex;

    // Iterate until the N-1 elements
    for (int i = 0; i < arrSize - 1; ++i)
    {
        // Set the first unsorted element
        // as the minimum value
        minIndex = i;

        // Iterate through the unsorted elements only
        for (int j = i + 1; j < arrSize; ++j)
        {
            // set the new minimum value
            // if the saved minimum value is higher
            // than the current index value

            //Checks if the next element is smaller than the previous element so that it can assign a new minIndex.
            if (arr[0][j] < arr[0][i])
                minIndex = j;
        }

        // Swap the the first unsorted element
        // with the minimum value
        swap(arr[0][i], arr[0][minIndex]);
    }
    cout << "res" << endl;
}
//Explain in white paper, put it on stackoverflow


void InsertionSort(int arr[ROWS][COLUMNS], int arrSize)
{
    // Iterate to all array's element
    for (int i = 0; i < arrSize; ++i)
    {
        // Set the current element
        // as reference value
        int refValue = arr[0][i];

        // variable to shift the element
        // to right position
        int j;

        // Iterate through the sorted element
        // to insert the reference value
        // in right position
        for (j = i - 1; j >= 0; --j)
        {
            // if the value of the current index
            // is greater than the reference value then
            // move the current value to right side
            // otherwise, put the reference value
            // in the current index
            if (arr[0][j] > refValue)
                arr[0][j + 1] = arr[0][j];
            else
                break;
        }

        // here's the line to put the reference value
        // in the current index (the right position)
        arr[0][j + 1] = refValue;
    }
}

void bubbleSort(int arr[ROWS][COLUMNS], int arrSize) {
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize -i-1; j++)
        {
            //Compares adjacent elements and swaps if one element is 
            //greater than its next element
            if (arr[0][j] > arr[0][j + 1]) {
                swap(arr[0][j], arr[0][j + 1]);
            }
        }
    }
}
