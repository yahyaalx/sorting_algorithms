#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @arr: The array
 * @a: index of the first element
 * @b: index of the second element
 */
void	swap(int *arr, int a, int b)
{
	int temp = arr[a];

	arr[a] = arr[b];
	arr[b] = temp;
}

/**
 * lomuto_partition - Lomuto partition for quicksort
 * @arr: The array
 * @low: start index of the partition
 * @high: end index of the partition
 * @size: size of the array.
 * Return: The final position of the pivot after partitioning
 */
int	lomuto_partition(int *arr, int low, int high, size_t size)
{
	int i = low - 1;
	int j = low;
	int pivot = arr[high];

	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(arr, i, j);
				print_array(arr, size);
			}
		}
		j++;
	}

	if (i + 1 != high)
	{
		swap(arr, i + 1, high);
		print_array(arr, size);
	}
	return (i + 1);
}

/**
 * quick_sort - sort an array of ints using the quicksort algorithm
 * @arr: array to be sorted
 * @size: size of the array
 */
void	quick_sort(int *arr, size_t size)
{
	int	low, high, p;
	int	stack[100];
	int	top = -1;

	if (!arr || size < 2)
	{
		return;
	}
	stack[++top] = 0;
	stack[++top] = size - 1;

	while (top >= 0)
	{
		high = stack[top--];
		low = stack[top--];
		p = lomuto_partition(arr, low, high, size);

		if ((p - 1) > low)
		{
			stack[++top] = low;
			stack[++top] = p - 1;
		}

		if ((p + 1) < high)
		{
			stack[++top] = p + 1;
			stack[++top] = high;
		}
	}
}
