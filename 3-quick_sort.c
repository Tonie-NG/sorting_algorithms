#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers
 * in aschighing order using the Quick sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: size of the array to be sorted.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursort(array, 0, size - 1, size);
}

/**
 * swap - function to swap 2 integers.
 *
 * @x: pointer to the first integer.
 * @y: pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - a functions that partitions an array int 2 sub arrays.
 * The first sub array which is assumed to on the left side of
 * the pivot contains values that are less than the pivot while
 * the rest of the values greater than teh pivot are in the second array.
 *
 * @array: The array to be sorted.
 * @low: the lowest index of the array.
 * @high: The highest index of the array.
 * @size: the size of the array (used mostly to print the array after swap).
 *
 * Return: the index of the pivot after partitioning.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j = low;

	while (j < high)
	{
		if (array[j] < pivot)
		{
			if (low < j)
			{
				swap(&array[low], &array[j]);
				print_array(array, size);
			}
			low = low + 1;
		}
		j++;
	}

	if (array[low] > pivot)
	{
		swap(&array[low], &array[high]);
		print_array(array, size);
	}

	return (low);
}

/**
 * recursort - recursive implementation of the quick sort.
 *
 * @array: The array to be sorted.
 * @low: the lowest index of the array.
 * @high: The highest index of the array.
 * @size: the size of the array (used mostly to print the array after swap).
 */
void recursort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		recursort(array, low, pivot - 1, size);
		recursort(array, pivot + 1, high, size);
	}
}
