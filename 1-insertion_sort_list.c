#include "sort.h"

/**
 * swap_nodes - Reorders two nodes in a doubly-linked list.
 * @h: Reference to the list's head pointer.
 * @n1: Address of the pointer to the first node involved in the swap.
 * @n2: Pointer to the second node involved in the swap.
 *
 * Adjusts pointers to swap positions of 'n1' and 'n2' in the list. Handles
 * special cases such as swapping at the head of the list.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Implements insertion sort on a doubly-linked list.
 * @list: Double pointer to the head of the list to be sorted.
 *
 * Iteratively advances through the list, repositioning each element to its
 * correct position in the sorted part of the list. Utilizes 'swap_nodes' for
 * reordering nodes where necessary. The list is printed after each swap to
 * demonstrate the sorting progress.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
