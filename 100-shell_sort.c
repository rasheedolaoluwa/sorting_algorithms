#include "sort.h"

/**
 * swap_ints - Exchanges the values of two integers within an array.
 * @a: Pointer to the first integer to be swapped.
 * @b: Pointer to the second integer to be swapped.
 *
 * Temporarily stores the value of the first integer to facilitate the swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Implements the shell sort algorithm on an integer array.
 * @array: Pointer to the array of integers to be sorted.
 * @size: The total number of elements in the array.
 *
 * This function improves insertion sort by comparing elements far apart
 * and then reducing the gap between elements to be compared. It specifically
 * utilizes the Knuth sequence for determining the gap between elements to
 * compare, leading to a more efficient sort. The array is printed after
 * completing the sort for each gap value.
 */
void shell_sort(int *array, size_t size)
{
	size_t x, i, j;

	if (array == NULL || size < 2)
		return;

	for (x = 1; x < (size / 3);)
		x = x * 3 + 1;

	for (; x >= 1; x /= 3)
	{
		for (i = x; i < size; i++)
		{
			j = i;

			while (j >= x && array[j - x] > array[j])
			{
				swap_ints(array + j, array + (j - x));
				j -= x;
			}
		}

		print_array(array, size);
	}
}
