#include "sort.h"
#include <stdio.h>
/**
 * merge_subarray - Merge two subarrays in sorted order.
 * @subarray: Subarray of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @front: Front index of the subarray.
 * @mid: Middle index of the subarray.
 * @back: Back index of the subarray.
 *
 * Description: Merges two subarrays in sorted order during merge sort.
 */
void merge_subarray(int *subarray, int *buffer, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + front, mid - front);

	printf("[right]: ");
	print_array(subarray + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];

	for (; i < mid; i++)
		buffer[k++] = subarray[i];

	for (; j < back; j++)
		buffer[k++] = subarray[j];

	for (i = front, k = 0; i < back; i++)
		subarray[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarray + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarray: Subarray of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @front: Front index of the subarray.
 * @back: Back index of the subarray.
 *
 * Description: Recursively applies the merge sort algorithm to a subarray.
 */
void merge_sort_recursive(int *subarray, int *buffer,
		size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarray, buffer, front, mid);
		merge_sort_recursive(subarray, buffer, mid, back);
		merge_subarray(subarray, buffer, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order using the
 *              merge sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);

	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
