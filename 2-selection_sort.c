#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection Sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp, swap_flag = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		swap_flag = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[min_index] > array[j])
			{
				min_index = j;
				swap_flag += 1;
			}
		}

		if (i != min_index)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}

		if (swap_flag != 0)
			print_array(array, size);
	}
}
