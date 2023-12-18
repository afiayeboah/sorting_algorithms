#include "sort.h"
#include <stddef.h>
#include <stdint.h>

/**
 * heapify - Transforms an array into a max heap.
 * @array: Array of integers.
 * @heap_size: Size of the heap data.
 * @index: Index of the current element.
 * @size: Size of the array.
 */
void heapify(int *array, size_t heap_size, size_t index, size_t size)
{
	size_t largest = index;
	size_t left_child = 2 * index + 1;
	size_t right_child = 2 * index + 2;
	int temp;

	if (left_child < heap_size && array[left_child] > array[largest])
		largest = left_child;
	if (right_child < heap_size && array[right_child] > array[largest])
		largest = right_child;
	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, heap_size, largest, size);
	}
}

/**
 * heap_sort - Sorts an array of integers using the heap sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i != SIZE_MAX; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);

		heapify(array, i, 0, size);
	}
}
