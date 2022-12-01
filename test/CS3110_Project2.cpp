//
//
//

#include "Algorithms.h"

using namespace std;

int main()
{
	cout << "Enter Array Size: ";
	int size = 0;
	cin >> size;

	cout << endl;

	int* arr = new int[size];

	populate(arr, size);
	print(arr, size);

	cout << "Enter k: ";
	int k = 0;
	cin >> k;

	int val = selectKthTwo(arr, size, k);
	cout << val << endl;
}
