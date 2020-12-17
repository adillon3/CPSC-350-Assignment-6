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
#include <iomanip>
#include <ctime>

string GetFileName();
void CheckFileNameValid(string& fileName);
bool GetYesOrNoInput(const string initialMessage);
int GetMenuInput(const string initialMessage, const int numMenuOptions);
int GetPositiveIntFromConsole(string itemsToGetNumberOf);

void GenerateRandomValuesForArray(double *&array, int numberOfValues);
void CreateArrayFromFile(double *&array, int &arraySize, string fileName);
void PrintDynamicArray(string arrayName, double *&array, int arraySize);
void CopyArray(double *&origionalArray, int arraySize, double *&duplicateArray);
double CalcTotalTime(double startTime, double endTime);
void UpdateFastestAndSlowest(double newTime, double &fastestTime, double &slowestTime,
                string newSortName, string &fastestSortName, string &slowestSortName);
