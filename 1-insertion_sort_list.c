#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 *
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Note: usage of i, j and k might seem less descriptive but it's
 * mostly due to the retriction of 80 characters per line.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, **k;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = i->next)
	{
		j = i->prev;

		for (k = &j; j != NULL && j->n > i->n; *k = i->prev)
		{
			(*k)->next = i->next;

			if (i->next != NULL)
				i->next->prev = *k;

			i->prev = (*k)->prev;
			i->next = *k;

			if ((*k)->prev != NULL)
			{
				(*k)->prev->next = i;
			}
			else
			{
				*list = i;
			}
			(*k)->prev = i;
			print_list(*list);
		}
	}
}
