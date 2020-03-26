#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void merge(int*, int, int, int);

void mergesort(int *array, int first, int last)
{
    int mid;

    //If the list is considered to be 0 or 1, it is already sorted, otherwise this code will run
    if(first < last)
    {
        //Need a mid point for the list
        mid = (first + last) / 2;

        mergesort(array, first, mid);

        mergesort(array, mid+1, last);

        merge(array, first, last, mid);
    }

    return;
}


void merge(int *array, int first, int last, int mid)
{
    int firstHalfIndex;
    int secondHalfIndex;
    int outputIndex;
    int output[50];

    firstHalfIndex = first;
    secondHalfIndex = mid + 1;
    outputIndex = first;

    while (firstHalfIndex <= mid && secondHalfIndex <= last)
    {
        if(array[firstHalfIndex] < array[secondHalfIndex])
        {
            output[outputIndex] = array[firstHalfIndex];

            outputIndex++;
            firstHalfIndex++;
        }
        else
        {
            output[outputIndex] = array[secondHalfIndex];

            outputIndex++;
            secondHalfIndex++;
        } 
    }

    while(firstHalfIndex <= mid)
    {
       output[outputIndex] = array[firstHalfIndex];

       outputIndex++;
       firstHalfIndex++; 
    }

    while(secondHalfIndex <= last)
    {
       output[outputIndex] = array[secondHalfIndex];
       outputIndex++;
       secondHalfIndex++; 
    }
    
    for(firstHalfIndex = first; firstHalfIndex < outputIndex; firstHalfIndex++)
    {
        array[firstHalfIndex] = output[firstHalfIndex];
    }

}

int main()
{
    srand(time(NULL));

    int count = 50;
    int array[50];
    int i;

    for(int i = 0; i < count; i ++)
    {
        array[i] = rand() % 1000;
    }

    cout << "Printing unsorted array: " << "\n";
    for(int i = 0; i < count; i ++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    mergesort(array, 0, count -1);

    cout <<"Merge sort completed: " << "\n";
    for(int i = 0; i < count; i ++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
    return 0;
}

