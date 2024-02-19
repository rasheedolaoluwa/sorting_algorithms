#include "sort.h"

/**
 * swap_ints - Exchange values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Temporary storage 'tmp' is used to hold the value of 'a' before the swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts integers in ascending order using the
 * bubble sort method.
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 *
 * Iterates through the array, comparing and swapping adjacent
 * elements if out of order. Continues until no swaps are required,
 * indicating the array is sorted. The array is printed after each
 * swap to show progress.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
