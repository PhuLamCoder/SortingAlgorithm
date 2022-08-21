#include "sortlib.h"
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

#define MAX 200000

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int main()
{
	int choice;
	int* a = new int[MAX];
	srand(time(0));
	// Assign random value for array
	for (int i = 0; i < MAX; i++)
		a[i] = rand();
	cout << "===>> TEST SORTING ALGORITHMS WITH 200,000 ELEMENTS <<===\n";
	cout << " 1. Selection sort\n";
	cout << " 2. Bubble sort\n";
	cout << " 3. Insertion sort\n";
	cout << " 4. Merge sort (Use recursion to split the array)\n";
	cout << " 5. Quick sort (Use recursion)\n";
	cout << " 6. Heap sort (Use recursion to heapify the array)\n";
	cout << " 7. Radix sort\n";
	cout << " 8. Shell sort\n";
	cout << " 9. Binary insertion sort\n";
	cout << "10. Shaker sort\n";
	cout << "11. Interchange sort\n";
	cout << "12. Counting sort\n";
	cout << "Choose your algorithms: ";
	cin >> choice;
	clock_t start, end;
	start = clock();
	switch (choice)
	{
	case 1:
		selectionSort(a, MAX);
		break;
	case 2:
		bubbleSort(a, MAX);
		break;
	case 3:
		insertionSort(a, MAX);
		break;
	case 4:
		mergeSort(a, MAX);
		break;
	case 5:
		quickSort(a, MAX);
		break;
	case 6:
		heapSort(a, MAX);
		break;
	case 7:
		radixSort(a, MAX);
		break;
	case 8:
		shellSort(a, MAX);
		break;
	case 9:
		binaryInsertionSort(a, MAX);
		break;
	case 10:
		shakerSort(a, MAX);
		break;
	case 11:
		interchangeSort(a, MAX);
		break;
	case 12:
		countSort(a, MAX);
		break;
	}
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by program is: " << setprecision(5) << fixed
		<< time_taken << " seconds" << endl;
	//printArray(a, MAX);
	delete[]a;
	return 0;
}