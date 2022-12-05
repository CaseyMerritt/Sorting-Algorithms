//
//
//
#include "Algorithms.h"

/***************************************************/

//should use mergesort uses bubble rn
int selectKthOne(int arr[], int size, int k) {
	mergeSort(arr, 0, size - 1);
	//print(arr, size);

	return arr[k];
}

//mergesort
void mergeSort(int arr[], int const begin, int const end)
{
	if (begin >= end) {
		return;
	}

	int mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}

//merge portion of mergesort
void merge(int arr[], int const left, int const mid, int const right)
{
	int const arrOne = mid - left + 1;
	int const arrTwo = right - mid;

	int* leftArr = new int[arrOne];
	int* rightArr = new int[arrTwo];

	for (int i = 0; i < arrOne; i++) {
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < arrTwo; j++) {
		rightArr[j] = arr[mid + 1 + j];
	}

	int arrOneIndex = 0;
	int	arrTwoIndex = 0;
	int mergeIndex = left;

	while (arrOneIndex < arrOne && arrTwoIndex < arrTwo) {
		if (leftArr[arrOneIndex] <= rightArr[arrTwoIndex]) {
			arr[mergeIndex] = leftArr[arrOneIndex];
			arrOneIndex++;
		}
		else {
			arr[mergeIndex] = rightArr[arrTwoIndex];
			arrTwoIndex++;
		}
		mergeIndex++;
	}

	while (arrOneIndex < arrOne) {
		arr[mergeIndex]= leftArr[arrOneIndex];
		arrOneIndex++;
		mergeIndex++;
	}

	while (arrTwoIndex < arrTwo) {
		arr[mergeIndex] = rightArr[arrTwoIndex];
		arrTwoIndex++;
		mergeIndex++;
	}
	delete[] leftArr;
	delete[] rightArr;
}

/***************************************************/

//using quicksort iteratively
int selectKthTwo(int arr[], int size, int k) {
	quickSortIterative(arr, 0, size - 1);
	//print(arr, size);

	return arr[k];
}

//quicksort but iterative
void quickSortIterative(int arr[], int low, int high)
{
	int* stack = new int[high - low + 1];

	int top = -1;

	stack[++top] = low;
	stack[++top] = high;

	while (top >= 0) {
		high = stack[top--];
		low = stack[top--];

		int p = partition(arr, low, high);//uses same partition as others

		if (p - 1 > low) {
			stack[++top] = low;
			stack[++top] = p - 1;
		}

		if (p + 1 < high) {
			stack[++top] = p + 1;
			stack[++top] = high;
		}
	}

	delete[] stack;
}

/***************************************************/

//using quicksort recursively
int selectKthThree(int arr[], int size, int k) {
	quickSort(arr, 0, size - 1);
	//print(arr, size);

	return arr[k];
}

//quicksort
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int p = partition(arr, low, high);

		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}

//partition part of quicksort used in others as well
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	int temp = arr[high];
	arr[high] = arr[i + 1];
	arr[i + 1] = temp;
	return (i + 1);
}

/***************************************************/

//using quicksort but with median of medians modification
int selectKthFour(int arr[], int size, int k) {
	return arr[k];
}

/***************************************************/

//populates array with random values
void populate(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
	}
}

//prints array
void print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}

	cout << endl;
}

//basic sort
int basicSort(int arr[], int size, int k) {
	int smallestPos = 0;

	for (int i = 0; i < size; i++) {
		smallestPos = i;
		for (int j = i; j < size; j++) {
			if (arr[j] < arr[smallestPos]) {
				smallestPos = j;
			}
		}

		if (smallestPos != i) {
			int temp = arr[i];
			arr[i] = arr[smallestPos];
			arr[smallestPos] = temp;
		}

		if (i + 1 == (size - 1)) {
			break;
		}
	}

	print(arr, size);
	return arr[k];
}

/***************************************************/