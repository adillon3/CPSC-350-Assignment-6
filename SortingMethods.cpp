/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 06
 *******************************/

#include "SortingMethods.h"

void BubbleSort(double *&array, int arraySize)
{
  for (int i = 0; i < arraySize - 1; ++i)
  {
    // Last i elements are already in place
    for (int j = 0; j < arraySize - i - 1; ++j)
    {
      if (array[j] > array[j + 1])
      {
        double temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void SelectionSort(double *&array, int arraySize)
{
  int minimumIndex;
  double temp;

  // One by one move boundary of unsorted subarray
  for(int i = 0; i < arraySize - 1; i++)
  {
    // Find the minimum element in unsorted array
    minimumIndex = i;
    for(int j = i + 1; j < arraySize; j++)
    {
      if(array[j] < array[minimumIndex])
      {
        minimumIndex = j;
      }
    }//END for(int j = i + 1; j < n; j++)

    //Swapping
    temp = array[minimumIndex];
    array[minimumIndex] = array[i];
    array[i] = temp;
  }//END for(int i = 0; i < n - 1; i++)
}

void InsertionSort(double *&array, int arraySize)
{
  double key = 0;
  int j   = 0;

  for(int i = 1; i < arraySize; i++)
  {
    key = array[i];
    j = i - 1;

    while(j >= 0 && array[j] > key)
    {
      array[j + 1] = array[j];
      j = j - 1;
    }//ENDwhile(j >= 0 && array[j] > key)
    array[j + 1] = key;
  }//END for(int i = 1; i < arraySize; i++)
}

void Merge(double *&array, int low, int mid, int high)
{
  int leftSize = mid - low + 1;
  int rightSize = high - mid;

  double leftAr[leftSize];
  double rightAr[rightSize];

  for (int i = 0; i < leftSize; i++)
  {
    leftAr[i] = array[low + i];
  }

  for (int j = 0; j < rightSize; j++)
  {
    rightAr[j] = array[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = low;

  while (i < leftSize && j < rightSize)
  {
    if (leftAr[i] <= rightAr[j])
    {
      array[k] = leftAr[i];
      i++;
    }
    else
    {
      array[k] = rightAr[j];
      j++;
    }
    k++;
  }

  while (i < leftSize)
  {
    array[k] = leftAr[i];
    i++;
    k++;
  }

  while (j < rightSize)
  {
    array[k] = rightAr[j];
    j++;
    k++;
  }
}

void MergeSort(double *&array, int low, int high)
{
  if(low >= high)
  {
      return;
  }

  int mid = (low + high - 1)/2;

  MergeSort(array, low, mid);
  MergeSort(array, mid + 1, high);
  Merge(array, low, mid, high);
}

int Partition (double *&array, int low, int high)
{
  double pivotIndex = array[high];
  int i = (low - 1);

  for(int j = low; j <= high - 1; j++)
  {
    if(array[j] < pivotIndex)
    {
      i++;
      //swapping
      double temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  //swapping
  double temp = array[i + 1];
  array[i + 1] = array[high];
  array[high] = temp;

  return (i + 1);
}

void QuickSort(double *&array, int low, int high)
{
  if(low < high)
  {
    int partitionIndex = Partition(array, low, high);

    QuickSort(array, low, partitionIndex - 1);
    QuickSort(array, partitionIndex + 1, high);
  }
}
