#include "sort.h"

/**
 * bubble_sort - sort an array of ints using bubble sort
 * @arr: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *arr, size_t size)
{
	unsigned int i;
unsigned int j;
	int temp;
	int swapped;

i = 0;

	if (size <= 1)
		return;

	while (i < size - 1)
	{
		swapped = 0;
j = 0;

		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				print_array(arr, size);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
		{
			break;
		}
		i++;
	}
}
