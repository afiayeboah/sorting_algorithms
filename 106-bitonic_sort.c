#include "sort.h"

/**
 * swap_values - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_values(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Merge a bitonic sequence in an array.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence.
 * @seq: The size of the sequence.
 * @direction: The direction to merge.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char direction)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((direction == 'U' && array[i] > array[i + jump]) ||
				(direction == 'D' && array[i] < array[i + jump]))
				swap_values(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, direction);
		bitonic_merge(array, size, start + jump, jump, direction);
	}
}

/**
 * bitonic_build - Build a bitonic sequence in an array.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence.
 * @seq: The size of the sequence.
 * @direction: The direction to build.
 */
void bitonic_build(int *array, size_t size, size_t start, size_t seq, char direction)
{
	size_t cut = seq / 2;

	if (seq > 1)
	{
		bitonic_build(array, size, start, cut, 'U');
		bitonic_build(array, size, start + cut, cut, 'D');
		bitonic_merge(array, size, start, seq, direction);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 *                using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (i.e., size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_build(array, size, 0, size, 'U');
}
