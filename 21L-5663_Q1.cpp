#include <iostream>
using namespace std;

void merge(int* arr, int l1, int l2, int r1, int r2);

void mergeSort(int* arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, mid + 1, end);
	}
}

void merge(int* arr, int l1, int l2, int r1, int r2)
{
	int* temp = new int[r2 - l1 + 1];
	int i = l1, j = r1, k = 0;
	while (i <= l2 && j <= r2)
	{
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i <= l2)
	{
		temp[k] = arr[i];
		i++;
		k++;

	}
	
	while (j <= r2)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}

	int start;
	for (start = l1, k = 0; start <= r2; start++, k++)
	{
		arr[start] = temp[k];
	}

	delete[] temp;
	temp = 0;
}

int main()
{
	int n = 0;
	cout << "Enter the number of Associations to be made : ";
	cin >> n;
	n = 2 * n;
	int* arr = new int(n);
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the building speed of worker " << i + 1 << " : ";
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);

	int sum = 0;
	for(int i = 0; i < n; )
	{
		sum += arr[i];
		i = i+2;
	}
	
	cout << "The maximum value possible of the sum of building speeds of all the associations is : " << sum;
	cout << endl << endl;
	
	system("pause");
	return 0;
}