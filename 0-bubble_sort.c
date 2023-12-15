#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 *
 * @array: the unsorted array to be sorted
 * @size: number of elements in @array
 */

void bubble_sort(int *array, size_t size)
{
	size_t j;
	size_t i = 0;
	int temp;
	int bool = 0;

	do
	{
		bool = 0;
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				bool = 1;
			}
		}
		i++;
	} while (bool == 1);
}
