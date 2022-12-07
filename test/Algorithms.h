#pragma once
//Author: Casey Merrit
//CS3310 Design and Analysis of Algorithms
//Project 2: Kth selection algorithms

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

/********************************************************************/
//Uses basic merge sort for sorting

int selectKthOne(int arr[], int size, int k);
void mergeSort(int arr[], int const begin, int const end);
void merge(int arr[], int const left, int const mid, int const right);

/********************************************************************/
//uses quicksort but iterative implementation

int selectKthTwo(int arr[], int size, int k);
void quickSortIterative(int arr[], int low, int high);
//same partition as recursive quicksort

/********************************************************************/
//uses quicksort but recursive implementation

int selectKthThree(int arr[], int size, int k);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

/********************************************************************/
//uses medians of medians 

int selectKthFour(int arr[], int size, int k);
int partitionMM(int arr[], int low, int high, int x);
int quickSortMM(int arr[], int low, int high, int k);
int findMedian(int arr[], int n);

/********************************************************************/
//util functions

void populate(int* arr, int size);//randomly populate array with ints from 1 to 100
void print(int arr[], int size);//prints array on one line

/********************************************************************/
