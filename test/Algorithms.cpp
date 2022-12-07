//Author: Casey Merrit
//CS3310 Design and Analysis of Algorithms
//Project 2: Kth selection algorithms

#include "Algorithms.h"

/***************************************************/

//Uses mergesort
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

	int IndexO = 0;
	int	IndexT = 0;
	int IndexM = left;

	while (IndexO < arrOne && IndexT < arrTwo) {
		if (leftArr[IndexO] <= rightArr[IndexT]) {
			arr[IndexM] = leftArr[IndexO];
			IndexO++;
		}
		else {
			arr[IndexM] = rightArr[IndexT];
			IndexT++;
		}
		IndexM++;
	}

	while (IndexO < arrOne) {
		arr[IndexM]= leftArr[IndexO];
		IndexO++;
		IndexM++;
	}

	while (IndexT < arrTwo) {
		arr[IndexM] = rightArr[IndexT];
		IndexT++;
		IndexM++;
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
	int p = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < p) {
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
	return quickSortMM(arr, 0, size - 1, k);
}

//partition part of quicksort but mm
int partitionMM(int arr[], int low, int high, int x)
{
	int i;
	for (i = low; i < high; i++) {
		if (arr[i] == x) {
			break;
		}
	}
	int temp = arr[i];
	arr[i] = arr[high];
	arr[high] = temp;

	i = low;
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= x)
		{
			temp = arr[i];
			arr[i] = arr[high];
			arr[i] = temp;
			i++;
		}
	}
	temp = arr[i];
	arr[i] = arr[high];
	arr[high] = temp;
	return i;
}

//sort using MM
int quickSortMM(int arr[], int low, int high, int k)
{
	if (k > 0 && k <= high - low + 1)
	{
		int n = high - low + 1;
		int i;
		int* median = new int[(n + 4) / 5];

		for (i = 0; i < n / 5; i++) {
			median[i] = findMedian(arr + low + i * 5, 5);
		}

		if (i * 5 < n)
		{
			median[i] = findMedian(arr + low + i * 5, n % 5);
			i++;
		}

		// Find median of all medians using recursive call.
		// If median[] has only one element, then no need
		// of recursive call
		int medOfMed = (i == 1) ? median[i - 1] : quickSortMM(median, 0, i - 1, i / 2);

		delete[] median;

		int pos = partitionMM(arr, low, high, medOfMed);

		if ((pos - low) == (k - 1)) {
			return arr[pos];
		}
		if ((pos - low) > (k - 1)) {
			return quickSortMM(arr, low, pos - 1, k);
		} 

		return quickSortMM(arr, pos + 1, high, k - pos + low - 1);
	}
}

int findMedian(int arr[], int n) {
	sort(arr, arr + n);  // Sort the array uses a built in library sort algo
	return arr[n / 2];
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

/***************************************************/