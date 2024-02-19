#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Exchanges the values of two integers within an array.
 * @a: Pointer to the first integer to be swapped.
 * @b: Pointer to the second integer to be swapped.
 *
 * This function temporarily stores the value of the first integer,
 * swaps the values, and ensures both integers have their values exchanged.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Organizes a segment of an array around a pivot using the
 * Lomuto partition scheme.
 * @array: The entire array of integers.
 * @size: The total size of the array.
 * @left: The index at which the segment begins.
 * @right: The index at which the segment ends.
 *
 * This function selects the last element as the pivot, reorders the array so
 * that all elements less than the pivot come before it, while all elements
 * greater come after. It then returns the index of the pivot after
 * partitioning.
 *
 * Return: Index where partition is divided.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, top, bot;

	pivot = array + right;
	for (top = bot = left; bot < right; bot++)
	{
		if (array[bot] < *pivot)
		{
			if (top < bot)
			{
				swap_ints(array + bot, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap_ints(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - Applies the quicksort algorithm recursively using the Lomuto
 * partition scheme.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the array segment to be sorted.
 * @right: The ending index of the array segment to be sorted.
 *
 * This function recursively sorts the array by partitioning it around a pivot
 * chosen according to the Lomuto partition scheme, then separately sorting
 * the partitions before and after the pivot.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers into ascending order using the
 * quicksort algorithm.
 * @array: The array of integers to sort.
 * @size: The total size of the array.
 *
 * This sorting function employs the Lomuto partition scheme to efficiently
 * sort the array.
 * It prints the array after each significant change to facilitate observation
 * of the sorting process.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
