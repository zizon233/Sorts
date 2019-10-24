#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include "Sorts.h"
using namespace std;

int main() {
	clock_t start, end;
	int n;
	cin >> n;
	vector<int> arr, arr2, arr3, arr4;
	for (int i = 0; i < n; i++) {
		int a;
		a = rand();
		arr.push_back(a);
		arr2.push_back(a);
		arr3.push_back(a);
		arr4.push_back(a);
	}
	start = clock();
	Heap_sort(arr);
	end = clock();
	cout << "Heap Sort : " << (double)(end - start) << "ms" << endl;
	
	start = clock();
	sort(arr2.begin(), arr2.end());
	end = clock();
	cout << "STL Sort : " << (double)(end - start) << "ms" << endl;
	
	start = clock();
	Quick_sort(arr3, 0, n-1);
	end = clock();
	cout << "Quick Sort : " << (double)(end - start) << "ms" << endl;
	
	start = clock();
	bubble_sort(arr4);
	end = clock();
	cout << "Bubble Sort : " << (double)(end - start) << "ms" << endl;
	return 0;
}