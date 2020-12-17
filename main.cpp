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
   clock_t startTime;
   clock_t endTime;
   double totalTime   = 0;
   double fastestTime = 0;
   double slowestTime = 0;
   string fastestSortName;
   string slowestSortName;

   //Array variables
   int    arraySize       = 0;
   double* bubbleArray    = nullptr;
   double* insertArray    = nullptr;
   double* selectionArray = nullptr;
   double* mergeArray     = nullptr;
   double* quickArray     = nullptr;
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


   cout << fixed;

   cout << "Now running Bubble Sort\n";
   startTime = clock();
   cout << " - Start: " << to_string(startTime) << endl << endl;
   cout << "    sorting...\n\n";
   BubbleSort(bubbleArray, arraySize);
   endTime = clock();
   cout << " - End:   " << to_string(endTime) << endl;
   totalTime = CalcTotalTime(startTime, endTime);
   cout << "Total time elapsed: " << totalTime << " seconds\n\n\n";
   UpdateFastestAndSlowest(totalTime, fastestTime, slowestTime, "Bubble Sort",
                            fastestSortName, slowestSortName);

   cout << "Now running Selection Sort\n";
   startTime = clock();
   cout << " - Start: " << to_string(startTime) << endl << endl;
   cout << "    sorting...\n\n";
   SelectionSort(selectionArray, arraySize);
   endTime = clock();
   cout << " - End:   " << to_string(endTime) << endl;
   totalTime = CalcTotalTime(startTime, endTime);
   cout << "Total time elapsed: " << totalTime << " seconds\n\n\n";
   UpdateFastestAndSlowest(totalTime, fastestTime, slowestTime, "Selection Sort",
                            fastestSortName, slowestSortName);

   cout << "Now running Insertion Sort\n";
   startTime = clock();
   cout << " - Start: " << to_string(startTime) << endl << endl;
   cout << "    sorting...\n\n";
   InsertionSort(insertArray, arraySize);
   endTime = clock();
   cout << " - End:   " << to_string(endTime) << endl;
   totalTime = CalcTotalTime(startTime, endTime);
   cout << "Total time elapsed: " << totalTime << " seconds\n\n\n";
   UpdateFastestAndSlowest(totalTime, fastestTime, slowestTime, "Insertion Sort",
                            fastestSortName, slowestSortName);

   cout << "Now running Merge Sort\n";
   startTime = clock();
   cout << " - Start: " << to_string(startTime) << endl << endl;
   cout << "    sorting...\n\n";
   MergeSort(mergeArray, 0, arraySize - 1);
   endTime = clock();
   cout << " - End:   " << to_string(endTime) << endl;
   totalTime = CalcTotalTime(startTime, endTime);
   cout << "Total time elapsed: " << totalTime << " seconds\n\n\n";
   UpdateFastestAndSlowest(totalTime, fastestTime, slowestTime, "Merge Sort",
                            fastestSortName, slowestSortName);

   cout << "Now running Quick Sort\n";
   startTime = clock();
   cout << " - Start: " << to_string(startTime) << endl << endl;
   cout << "    sorting...\n\n";
   QuickSort(quickArray, 0, arraySize - 1);
   endTime = clock();
   cout << " - End:   " << to_string(endTime) << endl;
   totalTime = CalcTotalTime(startTime, endTime);
   cout << "Total time elapsed: " << totalTime << " seconds\n\n\n";
   UpdateFastestAndSlowest(totalTime, fastestTime, slowestTime, "Quick Sort",
                            fastestSortName, slowestSortName);

   if(printArrayBool)
   {
     cout << "\n * Sorted order *\n";
     PrintDynamicArray("Bubble Array", bubbleArray, arraySize);
   }

   cout << "Fastest and Slowest\n\n";
   cout << " - The slowest sorting algorithm was " << slowestSortName << " and took " << slowestTime << " seconds to complete.\n";
   cout << " - The fastest sorting algorithm was " << fastestSortName << " and took " << fastestTime << " seconds to complete.\n\n";
   cout << fastestSortName << " was " << slowestTime - fastestTime << " seconds faster than " << slowestSortName << endl;



   cout << "\n\nThank you!\n\n";
   return 0;
 }
