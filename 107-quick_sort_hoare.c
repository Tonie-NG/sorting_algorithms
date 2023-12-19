#include "sort.h"

/**
 * quick_sort_hoare - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 * This function uses the hoare partition scheme.
 *
 * @array: the array to be sorted.
 * @size: size of the array to be sorted.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_recur(array, 0, size - 1, size);
}

/**
 * hoare_recur - recursive implementation of the quick sort.
 *
 * @array: The array to be sorted.
 * @low: the lowest index of the array.
 * @high: The highest index of the array.
 * @size: the size of the array (used mostly to print the array after swap).
 */
void hoare_recur(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_parti(array, low, high, size);
		hoare_recur(array, low, pivot - 1, size);
		hoare_recur(array, pivot + 1, high, size);
	}
}

/**
 * hoare_parti - a functions that partitions an array int 2 sub arrayS
 * using the hoare partition scheme.
 *
 * @array: The array to be sorted.
 * @low: the lowest index of the array.
 * @high: The highest index of the array.
 * @size: the size of the array (used mostly to print the array after swap).
 *
 * Return: the index of the pivot after partitioning.
 */
int hoare_parti(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;
	int temp;

	while (i < j)
	{
		do {
			i = i + 1;
		} while (array[i] < pivot);

		do {
			j = j - 1;
		} while (array[j] > pivot);

		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	return (i);
}
