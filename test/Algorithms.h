#pragma once
//
//
//
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

/********************************************************************/

int selectKthOne(int arr[], int size, int k);
void mergeSort(int arr[], int const begin, int const end);
void merge(int arr[], int const left, int const mid, int const right);

/********************************************************************/

int selectKthTwo(int arr[], int size, int k);
void quickSortIterative(int arr[], int low, int high);
//same partition as recursive quicksort

/********************************************************************/

int selectKthThree(int arr[], int size, int k);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

/********************************************************************/

int selectKthFour(int arr[], int size, int k);

/********************************************************************/

void populate(int* arr, int size);
void print(int arr[], int size);
int basicSort(int arr[], int size, int k);

/********************************************************************/
