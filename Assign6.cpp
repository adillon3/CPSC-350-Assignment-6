/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 06
 *******************************/

#include "Assign6.h"

 string GetFileName()
 {
   string fileName;
   cout << "Please enter a file to check: " ;
   getline(cin, fileName);
   return fileName;
 }

 void CheckFileNameValid(string& fileName)
 {
   ifstream inFile;
   bool isNotValid = true;

   do
   {
     inFile.open(fileName.c_str());

     //check if file exists
     if(inFile)
     {
       isNotValid = false; //is valid
     }
     else
     {
       cout << "Sorry, the file, \"" << fileName << "\", wasn't found.\n";
       fileName = GetFileName();//prompting for valid input

       isNotValid = true; //repeat loop
     }

     inFile.close();
   } while(isNotValid);
 }

 bool GetYesOrNoInput(const string initialMessage)
 {
   char gameChoice;
   bool invalidInput = true;

   cout << initialMessage << endl;

   do
   {
     cout << "Please enter either \'Y\' for \"Yes\" or \'N\' for \"No\": ";
     cin.get(gameChoice);
     cin.ignore(100000000, '\n');
     cout << endl;
     gameChoice = toupper(gameChoice);

     if(gameChoice == 'Y' || gameChoice == 'N')
     {
       invalidInput = false;
     }
     else
     {
       invalidInput = true;
       cout << "Sorry, \'" << gameChoice << "\' is invalid.\n";
     }
   }while(invalidInput);

   if(gameChoice == 'Y')
   {
     return true;
   }
   else
   {
     return false;
   }

 }

 int GetMenuInput(const string initialMessage, const int numMenuOptions)
 {
   bool valid = false;
   int menuChoice = 0;

   do
   {
     cout << initialMessage;
     cin >> menuChoice;
     if(cin.fail())
     {
       cin.clear();
       cin.ignore(100000000, '\n');
       cout << "\nSorry, please enter numeric input.\n\n";

       valid = false;
     }
     else if(menuChoice > 0 && menuChoice <= numMenuOptions)
     {
       valid = true;
     }
     else
     {
       cout << "\nSorry, please enter a value between 1 and " << numMenuOptions << endl << endl;
       valid = false;
     }

   } while(!valid);
   cin.ignore(100000000, '\n');

   return menuChoice;
 }

 int GetPositiveIntFromConsole(string itemsToGetNumberOf)
 {
   bool invalidInput = true;
   int returnInt = 0;
   long int inputInt;

   do
   {
     cout << "Please enter the number of " << itemsToGetNumberOf << " you would like: ";
     cin  >> inputInt;
     cin.ignore(100000000, '\n');

     if(cin.fail())
     {
       cin.clear();
       cin.ignore(100000000, '\n');
       cout << "Sorry, please enter the number of " << itemsToGetNumberOf << " as an integer.\n";
     }
     else if(inputInt <= 0)
     {
       cout << "Sorry, the number of " << itemsToGetNumberOf << " must be a positive, non-zero, number.\n";
       invalidInput = true;
     }
     else
     {
       returnInt = (unsigned int)inputInt;
       invalidInput = false;
     }
   }while(invalidInput);

   cout << endl;

   return returnInt;
 }

 void GenerateRandomValuesForArray(float *&array, int numberOfValues)
 {
   array = new float[numberOfValues];

   srand (time(NULL));

   for(int i = 0; i < numberOfValues; ++i)
   {
     array[i] = ((float) rand()) / (float) RAND_MAX;
   }
 }

 void FillInArrayFromFile(float *&array, string fileName)
 {

 }

 void PrintDynamicArray(string arrayName, float *&array, int arraySize)
 {
   if(array == nullptr)
   {
     cout << arrayName << " is empty: could not print.\n\n";
     return;
   }

   cout << arrayName << endl;

   for(int i = 0; i < arraySize; ++i)
   {
     cout << " " << array[i] << endl;
   }
   cout << endl;
 }

 void CopyArray(float *&origionalArray, int arraySize, float *&duplicateArray)
 {
   if(duplicateArray != nullptr)
   {
     delete[] duplicateArray;
   }

   duplicateArray = new float[arraySize];

   for(int i = 0; i < arraySize; ++i)
   {
     duplicateArray[i] = origionalArray[i];
   }
 }
