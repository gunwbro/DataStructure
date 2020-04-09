#include <stdio.h>

void Sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
int main(void)
{
	int a[5] = { 3,2,5,4,1 };
	Sort(a, sizeof(a) / sizeof(int));

	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);

	return 0;
}