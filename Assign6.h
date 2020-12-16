/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 06
 *******************************/

#include <iostream>
using namespace std;

#include <string>
#include <fstream>

string GetFileName();
void CheckFileNameValid(string& fileName);
bool GetYesOrNoInput(const string initialMessage);
int GetMenuInput(const string initialMessage, const int numMenuOptions);
int GetPositiveIntFromConsole(string itemsToGetNumberOf);

void GenerateRandomValuesForArray(float *&array, int numberOfValues);
void FillInArrayFromFile(float *&array, string fileName);
void PrintDynamicArray(string arrayName, float *&array, int arraySize);
void CopyArray(float *&origionalArray, int arraySize, float *&duplicateArray);
