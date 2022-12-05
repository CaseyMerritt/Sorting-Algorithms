//
//
//

#include "Algorithms.h"
#include <algorithm>
#include <chrono>

using namespace std;

int main()
{
	cout << "Enter Array Size: ";
	int size = 0;
	cin >> size;

	cout << endl;

	int* arr = new int[size];

	populate(arr, size);
	//print(arr, size);

	cout << "Enter k: ";
	int k = 0;
	cin >> k;

	int val = 0;

	auto begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000; i++) {
		//val = selectKthOne(arr, size, k);

		val = selectKthTwo(arr, size, k);

		//val = selectKthThree(arr, size, k);

		populate(arr, size);
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	printf("Average time measured: %.8f seconds.\n", (elapsed.count() * 1e-9) / 10000);
}
