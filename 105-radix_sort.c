#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int getMax(int *array, int size)
{
	int max = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * countingSort - Sort the significant digits of an array of integers
 *                in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void countingSort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		buff[count[(array[i - 1] / sig) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / sig) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int *buff;
	int max, sig;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = getMax(array, size);

	for (sig = 1; max / sig > 0; sig *= 10)
	{
		countingSort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
