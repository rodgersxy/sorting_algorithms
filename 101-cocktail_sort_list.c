#include "sort.h"
/**
* cocktail_sort_list - function that sorts a doubly linked list of integers
* in ascending order using the Cocktail shaker sort algorithm
* @list: the Pointer to the head of the doubly linked list
* Return: Nothing
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;

		for (current = current->prev; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @list: Pointer to the head of the doubly linked list
* @node1: First node to swap
* @node2: Second node to swap
* Return: Nothing
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
	print_list(*list);
}
