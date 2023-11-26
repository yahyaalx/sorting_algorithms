#include "sort.h"
/**
 * getMax - find the maximum element and returns that value
 * @array: array of ints
 * @size: size of the array
 * Return: the max int of the array
 */
int	getMax(int *array, size_t size)
{
	int max;
	size_t i = 1;

	max = array[0];

	while (i < size)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		i++;
	}
	return (max);
}
/**
 * radix_sort - logic behind the radix sorting
 * @array: array of ints to sort
 * @size: size of the array
 * @exp: digit pos during the sorting
 */
void	radix_sort2(int *array, size_t size, int exp)
{
	const int	base = 10;
	int	output[100];
	int	count[100];
	int	i;
	int k;
	size_t j = 0;

	for (i = 0; i < base; i++)
		count[i] = 0;

	while (j < size)
	{
		count[(array[j] / exp) % base]++;
		j++;
	}

	i = 1;
	while (i < base)
	{
		count[i] += count[i - 1];
		i++;
	}

k = size - 1;

	while (k >= 0)
	{
		output[count[(array[k] / exp) % base] - 1] = array[k];
		count[(array[k] / exp) % base]--;
		k--;
	}
	j = 0;

	while (j < size)
	{
		array[j] = output[j];
		j++;
	}
}
/**
 * radix_sort - sort an array of ints using radix sort
 * @array: array to sort
 * @size: size of the array
 */
void	radix_sort(int *array, size_t size)
{
int max;
int exp;

	if (array == NULL || size < 2)
		return;

max = getMax(array, size);
exp = 1;

	while (max / exp > 0)
	{
		radix_sort2(array, size, exp);
		print_array(array, size);
		exp *= 10;
	}
}
