#include "sort.h"

/**
 * shell_sort -  a function that sorts an array of integers
 * in ascending order using the Shell sort algorithm,
 * using the Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of @array.
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;
	size_t i, j;
	int temp, p;

	if (array == NULL || size < 2)
		return;

	while (n < size / 3)
		n = (n * 3) + 1;

	while (n >= 1)
	{
		for (i = n; i < size; i++)
		{
			p = array[i];
			for (j = i; j >= n && array[j - n] > p; j -= n)
			{
				temp = array[j];
				array[j] = array[j - n];
				array[j - n] = temp;
			}
		}
		n /= 3;
		print_array(array, size);
	}
}
