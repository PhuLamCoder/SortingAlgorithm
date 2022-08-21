#include "sortlib.h"
// Function to swap two elements
template <class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void selectionSort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		if (min != i)
			swap(a[i], a[min]);
	}
}

void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}

void insertionSort(int a[], int n)
{
	int saved;
	for (int i = 1; i < n; i++)
	{
		saved = a[i];
		int j;
		for (j = i; j > 0 && saved < a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = saved;
	}
}

// Function to merge the two parts into one
void merge(int M[], int left, int mid, const int right)
{
	int* temp = new int[right - left + 1];
	if (!temp) return;
	int pos = 0;
	int i = left;
	int j = mid + 1;

	while (i <= mid || j <= right)
	{
		if ((i <= mid && j <= right && M[i] < M[j]) || j > right)
			temp[pos++] = M[i++];
		else
			temp[pos++] = M[j++];
	}

	for (i = 0; i < pos; i++)
		M[left + i] = temp[i];
	delete[]temp;
}
void mergeSort(int a[], int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, mid, right);
}
void mergeSort(int a[], int n)
{
	mergeSort(a, 0, n - 1);
}

void quickSort(int a[], int left, int right)
{
	if (left >= right) return;
	int i = left, j = right;
	int mid = a[(left + right) / 2];
	do
	{
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j)
			swap(a[i++], a[j--]);
	} while (i <= j);
	quickSort(a, left, j);
	quickSort(a, i, right);
}
void quickSort(int a[], int n)
{
	quickSort(a, 0, n - 1);
}

// Function to heapify the remain elements of array
void heapify(int a[], int n, int i)
{   // mảng a, n - số phần tử, i - đỉnh cần vun đống
	int max = i;    // Lưu vị trí đỉnh max ban đầu
	int l = i * 2 + 1;   // Vị trí con trái
	int r = l + 1;    // Vị trí con phải
	if (l<n && a[l] > a[max])
		max = l;  // Nếu tồn tại con trái lớn hơn cha, gán max = L
	if (r<n && a[r] > a[max])
		max = r;  // Nếu tồn tại con phải lớn hơn arr[max], gán max = r
	
	if (max != i)
	{   // Nếu max != i, tức là cha không phải lớn nhất
		swap(a[i], a[max]);   // Đổi chỗ cho phần tử lớn nhất làm cha
		heapify(a, n, max);   // Đệ quy vun các node phía dưới
	}
}
void heapSort(int a[], int n) // Base on selecting of selection sort
{
	// vun dong tu duoi len len de thanh heap
	for (int i = n / 2 - 1; i >= 0; i--)   // i chạy từ n/2 - 1 về 0 sẽ có n/2 đỉnh nhé!
		heapify(a, n, i);   // Vun từng đỉnh
	// Vòng lặp để thực hiện vun đống và lấy phần tử
	for (int j = n - 1; j > 0; j--)
	{   // chạy hết j == 1 sẽ dừng
		// mỗi lần j - 1, tương đương với k xét phần tử cuối 
		swap(a[0], a[j]);  // đổi chỗ phần tử lớn nhất
		heapify(a, j, 0);    // vun lại đống
	}
}

// Function to get the largest element from an array
int getMax(int a[], int n) 
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}
void countSort(int a[], int n)
{
	int max = getMax(a, n);
	int* count = new int[max + 1] {0};
	int i;
	for (i = 0; i < n; i++)
		count[a[i]]++;
	i = 0;
	for (int j = 0; j <= max; j++)
	{
		while (count[j] > 0)
		{
			a[i++] = j;
			count[j]--;
		}
	}
}

// Main function to implement radix sort
void radixSort(int a[], int size)
{
	const int radix = 10;
	const int digits = 6;
	std::queue<long> queues[radix];
	for (int i = 0, factor = 1; i < digits; factor *= radix, i++)
	{
		// Phan bo
		for (int j = 0; j < size; j++)
			queues[(a[j] / factor) % radix].push(a[j]);
		// Ket hop
		for (int j = 0, k = 0; j < radix; j++)
			while (!queues[j].empty())
			{
				a[k++] = queues[j].front();
				queues[j].pop();
			}
	}
}

void shellSort(int a[], int n)
{
	// Rearrange elements at each n/2, n/4, n/8, ... intervals
	// Based on insertion sort
	for (int interval = n / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < n; i++)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
			{
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}

void binaryInsertionSort(int a[], int n)
{
	int x, left, right, mid;
	for (int i = 1; i < n; i++)
	{
		x = a[i], left = 0, right = i - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (x > a[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		for (int j = i; j > left; j--)
			a[j] = a[j - 1];
		a[left] = x;
	}
}

void shakerSort(int a[], int n)
{   // Based on bubble sort
	int left = 0, right = n - 1;
	int k = 0, i;
	while (left < right)
	{
		for (i = left; i < right; i++)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		right = k;
		for (i = right; i > left; i--)
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		left = k;
	}
}

void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
