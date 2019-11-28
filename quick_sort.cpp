#include <iostream>
using namespace std;

void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int partition(int arr[], int low, int high, int size)
{
	int pivot = low;
	low = low + 1;
	while(true)
	{
		while(arr[low] < arr[pivot] && low < size) low++;
		while(arr[high] >= arr[pivot] && high > pivot) high--;
		int temp;
		if(low < high)
		{
			swap(&arr[low], &arr[high]);
		}
		else
		{
			swap(&arr[pivot], &arr[high]);
			pivot = high;
			return pivot;
		}
	}
}

void quickSort(int arr[], int low, int high, int size)
{
	if(low < high)
	{
		int pivot = partition(arr, low, high, size);
		quickSort(arr, low, pivot-1, pivot);
		quickSort(arr, pivot+1, high, size);
	}
}

int main()
{
	int arr[10] = { 23, 12, 69, 15, 3, 8, 36, 27, 20, 19 };
	cout << "Array before sorting..." << endl;
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	quickSort(arr, 0, 9, 10);
	cout << "Array after sorting..." << endl;
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}