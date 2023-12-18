#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: size of the array to be sorted.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
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
 * quick_sort_recursion - recursive implementation of the quick sort.
 *
 * @array: The array to be sorted.
 * @low: the lowest index of the array.
 * @high: The highest index of the array.
 * @size: the size of the array (used mostly to print the array after swap).
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int p;

	if (low >= 0 && high >= 0 && low < high)
	{
		p = partition(array, low, high, size);
		quick_sort_recursion(array, low, p, size);
		quick_sort_recursion(array, p + 1, high, size);
	}
}

/**
 * partition - A function to partition the array.
 * This function picks a pivot element from the array and
 * rearranges the elements such that elements smaller than the
 * pivot are on the left, and elements greater than the pivot
 * are on the right.
 *
 * @array: The array to be partitioned.
 * @low: The starting index of the array or subarray to be partitioned.
 * @high: The ending index of the array or subarray to be partitioned.
 * @size: The size of the array.
 *
 * Return: The final position of the pivot element after partitioning.
 */
int partition(int *array, int low, int high, size_t size)
{
	int n = ((high - low) / 2) + low;
	int pivot = array[n];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i = i + 1;
		} while (array[i] < pivot);

		do {
			j = j - 1;
		} while (array[j] > pivot);

		if (i >= j)
		{
			return (j);
		}

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}
