#include "sort.h"

/**
 * swap_ints - Exchange the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * 
 * Utilizes a temporary variable to hold the value of the first integer,
 * enabling the swap of values between the two integers.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order.
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 *
 * Iterates through the array to find the minimum element and swaps it
 * with the current position. The process repeats, moving the starting
 * point of the search one element forward each time until the array is sorted.
 * The array is printed after each swap to visualize the sorting progress.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
