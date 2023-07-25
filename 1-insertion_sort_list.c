#include "sort.h"

/**
 * insertion_sort_list - sorts a list using insertion sort
 * @list: the list to be sorted
 *
 * Return: Returns void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	listint_t *sorted;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		tmp = current->next;
		sorted = current->prev;

		while (sorted != NULL && sorted->n > current->n)
		{
			sorted->next = current->next;
			if (current->next != NULL)
				current->next->prev = sorted;

			current->prev = sorted->prev;
			if (sorted->prev != NULL)
				sorted->prev->next = current;
			else
				*list = current;
			current->next = sorted;
			sorted->prev = current;
			sorted = current->prev;
			print_list(*list);
		}
		current = tmp;
	}
}
