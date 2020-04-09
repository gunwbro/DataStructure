#include <stdio.h>

void Sort(int arr[], int n)
{
	int i, j, insData;
	for (i = 1; i < n; i++)
	{
		insData = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = insData;
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