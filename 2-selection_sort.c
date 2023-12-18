#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of @array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, pos;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		pos = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[pos] > array[j])
				pos = j;
		}
		if (pos != i)
		{
			temp = array[i];
			array[i] = array[pos];
			array[pos] = temp;
			print_array(array, size);
		}
	}
}
