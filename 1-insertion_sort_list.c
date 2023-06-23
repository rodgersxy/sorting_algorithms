#include "sort.h"
/**
* insertion_sort_list - Sorts a doubly linked list of integers
* in ascending order
* @list: Pointer to the head of the doubly linked list
* Return: Nothing
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;

	/*chexks if the list is empty or contains some elem*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	current = current->next;

	while (current != NULL)
	{
		while (current->prev && current->n < (current->prev)->n)
		{
			temp = current;
			if (current->next)
				(current->next)->prev = temp->prev;
			(current->prev)->next = temp->next;
			current = current->prev;
			temp->prev = current->prev;
			temp->next = current;

			if (current->prev)
				(current->prev)->next = temp;
			current->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
			current = current->prev;
		}

		current = current->next;
	}
}
