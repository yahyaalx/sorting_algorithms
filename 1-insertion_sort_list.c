#include "sort.h"

/**
 * insertion_sort_list - sort a linked list using the insertion sort algorithm.
 * @list: Pointer to the head of the linked list
 */
void	insertion_sort_list(listint_t **list)
{


	listint_t *current;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

current = (*list)->next;
	while (current != NULL)
	{
		listint_t *prevNode = current->prev;

		while (prevNode != NULL && current->n < prevNode->n)
		{
			temp = current->next;

			if (temp != NULL)
				temp->prev = prevNode;
			prevNode->next = temp;
			current->prev = prevNode->prev;
			current->next = prevNode;
			if (prevNode->prev != NULL)
				prevNode->prev->next = current;
			else
				*list = current;
			prevNode->prev = current;
			print_list(*list);
			prevNode = current->prev;
		}
		current = current->next;
	}
}
