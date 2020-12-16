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



   //Copy bubbleArray to other 4 arrays
   CopyArray(bubbleArray, arraySize, selectionArray);
   CopyArray(bubbleArray, arraySize, insertArray);
   CopyArray(bubbleArray, arraySize, mergeArray);
   CopyArray(bubbleArray, arraySize, quickArray);

   PrintDynamicArray("Insert Array", insertArray, arraySize);



   BubbleSort(bubbleArray, arraySize);
   SelectionSort(selectionArray, arraySize);
   InsertionSort(insertArray, arraySize);
   MergeSort(mergeArray, 0, arraySize - 1);
   QuickSort(quickArray, 0, arraySize - 1);

   PrintDynamicArray("Bubble Array", bubbleArray, arraySize);


   cout << "\n\nThank you!\n\n";
   return 0;
 }
