/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 06
 *******************************/

 #include "Assign6.h"
 #include "SortingMethods.h"

 int main(int argc, char* argv[])
 {
   const string FILE_OR_RANDOM_TEXT = "Would you like to get data from a file or would you like to randomly generate data?\n"
                                      " 1 - File\n"
                                      " 2 - Random\n"
                                      "Choice: ";
   const int FILE_OR_RANDOM_NUM_OPTIONS = 2;

   int menuChoice = 1;// 1 by default, for reading files

   int    arraySize      = 0;
   float* bubbleArray    = nullptr;
   float* insertArray    = nullptr;
   float* selectionArray = nullptr;
   float* mergeArray     = nullptr;
   float* quickArray     = nullptr;

   string fileName;

   //Getting input if commandline is blank
   if(argc < 2)
   {
     menuChoice = GetMenuInput(FILE_OR_RANDOM_TEXT, FILE_OR_RANDOM_NUM_OPTIONS);
   }

   //Get file
   if(menuChoice == 1)
   {
     //check command line variables
     if(!(argc < 2))
     {
       fileName = argv[1];
     }

     fileName = GetFileName();

     CheckFileNameValid(fileName);

     //CreateFromFile
     //return arraySize
   }
   else//Get random
   {
     cout << "How many values would you like to sort?\n";
     arraySize = GetPositiveIntFromConsole("values");

     GenerateRandomValuesForArray(bubbleArray, arraySize);

   }

   PrintDynamicArray("Bubble Array", bubbleArray, arraySize);



   //Copy bubbleArray to other 4 arrays**************************************************



   //bubbleSort(bubbleArray, arraySize);
   //SelectionSort(selectionArray, arraySize);
   //InsertionSort(insertArray, arraySize);
   //MergeSort(mergeArray, 0, arraySize - 1);
   QuickSort(bubbleArray, 0, arraySize - 1);

   PrintDynamicArray("Bubble Array", bubbleArray, arraySize);


   cout << "\n\nThank you!\n\n";
   return 0;
 }




















/* C++ implementation of QuickSort */


/*
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(float* a, float* b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot
int partition (float arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    cerr << " * PIVOT: " << pivot << endl;
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index
void quickSort(float arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array
void printArray(float arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main()
{
    float arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6; //= sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
*/
