#include "sort.h"

/**
 * heap_sort - a function that sorts an array of integers
 * in ascending order using the Heap sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int n = (size / 2) - 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (n >= 0)
	{
		heapify(array, size, n, size);
		n--;
	}

	n = size - 1;

	while (n > 0)
	{
		temp = array[0];
		array[0] = array[n];
		array[n] = temp;
		print_array(array, size);
		heapify(array, n, 0, size);
		n--;
	}
}

/**
 * heapify - a function that converts an array
 * into a heap data structure.
 *
 * @array: the input array.
 * @hsize: the size of the heap.
 * @n: the index of the current node in the heap.
 * @ogsize: the size of the first array for printing purposes.
 *
 * Description: This function rearranges the elements in the array to
 * satisfy the heap property. It compares the current node with its
 * left and right children, and swaps it with the largest child if needed.
 * The process is repeated recursively until the entire array is a heap.
 */
void heapify(int *array, int hsize, int n, size_t ogsize)
{
	int largest, left, right, temp;

	largest = n;
	left = 2 * n + 1;
	right = 2 * n + 2;

	if (left < hsize && array[left] > array[largest])
		largest = left;

	if (right < hsize && array[right] > array[largest])
		largest = right;

	if (largest != n)
	{
		temp = array[n];
		array[n] = array[largest];
		array[largest] = temp;
		print_array(array, ogsize);
		heapify(array, hsize, largest, ogsize);
	}
}
