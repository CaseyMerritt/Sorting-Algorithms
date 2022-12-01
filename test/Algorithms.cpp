//
//
//
#include "Algorithms.h"

/***************************************************/

//should use mergesort uses bubble rn
int selectKthOne(int arr[], int size, int k) {
	mergeSort(arr, 0, size - 1);
	print(arr, size);

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
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	// Create temp arrays
	int *leftArray = new int[subArrayOne];
	int	*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (int i = 0; i < subArrayOne; i++) {
		leftArray[i] = arr[left + i];
	}
	for (int j = 0; j < subArrayTwo; j++) {
		rightArray[j] = arr[mid + 1 + j];
	}

	int indexOfSubArrayOne = 0; // Initial index of first sub-array
	int	indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		arr[indexOfMergedArray]= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

/***************************************************/

//using quicksort iteratively
int selectKthTwo(int arr[], int size, int k) {
	quickSortIterative(arr, 0, size - 1);
	print(arr, size);

	return arr[k];
}

//quicksort but iterative
void quickSortIterative(int arr[], int low, int high)
{
	// Create an auxiliary stack
	int* stack = new int[high - low + 1];

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	stack[++top] = low;
	stack[++top] = high;

	// Keep popping from stack while is not empty
	while (top >= 0) {
		// Pop h and l
		high = stack[top--];
		low = stack[top--];

		// Set pivot element at its correct position
		// in sorted array
		int pi = partition(arr, low, high);

		// If there are elements on left side of pivot,
		// then push left side to stack
		if (pi - 1 > low) {
			stack[++top] = low;
			stack[++top] = pi - 1;
		}

		// If there are elements on right side of pivot,
		// then push right side to stack
		if (pi + 1 < high) {
			stack[++top] = pi + 1;
			stack[++top] = high;
		}
	}
}

/***************************************************/

//using quicksort recursively
int selectKthThree(int arr[], int size, int k) {
	quickSort(arr, 0, size - 1);
	print(arr, size);

	return arr[k];
}

//quicksort
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//partition part of quicksort
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