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
   const string OUTPUT_ARRAYS_TEXT  = "Would you like to output the array, both the inital and the sorted version?";

   bool printArrayBool = false;
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
     if((argc < 2))
     {
       fileName = GetFileName();
     }
     else
     {
       fileName = argv[1];
     }

     CheckFileNameValid(fileName);

     CreateArrayFromFile(bubbleArray, arraySize, fileName);
     cout << endl;
   }
   else//Get random
   {
     cout << "How many values would you like to sort?\n";
     arraySize = GetPositiveIntFromConsole("values");

     GenerateRandomValuesForArray(bubbleArray, arraySize);
   }//END else of if(menuChoice == 1)

   //Copy bubbleArray to other 4 arrays
   CopyArray(bubbleArray, arraySize, selectionArray);
   CopyArray(bubbleArray, arraySize, insertArray);
   CopyArray(bubbleArray, arraySize, mergeArray);
   CopyArray(bubbleArray, arraySize, quickArray);


   //Asking user if they would like to see the arrays outputted
   printArrayBool = GetYesOrNoInput(OUTPUT_ARRAYS_TEXT);

   if(printArrayBool)
   {
     cout << " *\n Initial order *\n";
     PrintDynamicArray("Bubble Array", bubbleArray, arraySize);
   }


   cout << "Now running Bubble Sort\n";
   cout << " - Start: " << endl;
   BubbleSort(bubbleArray, arraySize);
   cout << " - End:   " << endl << endl;

   cout << "Now running Selection Sort\n";
   cout << " - Start: " << endl;
   SelectionSort(selectionArray, arraySize);
   cout << " - End:   " << endl << endl;

   cout << "Now running Insertion Sort\n";
   cout << " - Start: " << endl;
   InsertionSort(insertArray, arraySize);
   cout << " - End:   " << endl << endl;

   cout << "Now running Merge Sort\n";
   cout << " - Start: " << endl;
   MergeSort(mergeArray, 0, arraySize - 1);
   cout << " - End:   " << endl << endl;

   cout << "Now running Quick Sort\n";
   cout << " - Start: " << endl;
   QuickSort(quickArray, 0, arraySize - 1);
   cout << " - End:   " << endl << endl;

   if(printArrayBool)
   {
     cout << "\n * Sorted order *\n";
     PrintDynamicArray("Bubble Array", bubbleArray, arraySize);
   }

   cout << "\n\nThank you!\n\n";
   return 0;
 }
