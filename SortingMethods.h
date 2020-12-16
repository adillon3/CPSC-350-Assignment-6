/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 06
 *******************************/
 #ifndef SORTINGMETHODS_H_
 #define SORTINGMETHODS_H_

 #include <iostream>
 using namespace std;

 #include <string>
 #include <fstream>

void BubbleSort(float *&array, int arraySize);
void SelectionSort(float *&array, int arraySize);
void InsertionSort(float *&array, int arraySize);
void Merge(float *&array, int low, int mid, int high);
void MergeSort(float *&array, int low, int high);
int Partition (float *&array, int low, int high);
void QuickSort(float *&array, int low, int high);


 #endif // SORTINGMETHODS_H_
