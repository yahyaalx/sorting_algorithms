#include "sort.h"

/**
 * selection_sort - sorts an array of ints using selection sort
 * @array: array to be sorted
 * @size: size of array
 */
void	selection_sort(int *array, size_t size)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int min_idx = 0;
	int	tmp;

	if (size < 2 || array == NULL)
		return;

	while (i < size - 1)
	{
		j = i + 1;
		min_idx = i;

		while (j < size)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
		{
			tmp = array[min_idx];
			array[min_idx] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
