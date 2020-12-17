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

void BubbleSort(double *&array, int arraySize);
void SelectionSort(double *&array, int arraySize);
void InsertionSort(double *&array, int arraySize);
void Merge(double *&array, int low, int mid, int high);
void MergeSort(double *&array, int low, int high);
int Partition (double *&array, int low, int high);
void QuickSort(double *&array, int low, int high);


 #endif // SORTINGMETHODS_H_
