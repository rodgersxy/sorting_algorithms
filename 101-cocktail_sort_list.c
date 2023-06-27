#include "sort.h"
/**
* forward_pass - to perform the forward pass of cocktail sort alg
* @list: pointer to the head node of the list
* @end: pointer to the end node of the current pass
* Return: 1 if swap occured else 0
*/
int forward_pass(listint_t **list, listint_t *end)
{
	listint_t *current = *list;
	int swapped = 0;

	while (current->next != end)
	{
		if (current->n > current->next->n)
		{
			/*swap adjacent nodes*/
			if (current->prev != NULL)
				current->prev->next = current->next;
			else
				*list = current->next;
			current->next->prev = current->prev;
			current->prev = current->next;
			current->next = current->next->next;
			current->prev->next = current;
			if (current->next != NULL)
				current->next->prev = current;
			swapped = 1;
			print_list(*list);
		}
		else
		{
			current = current->next;
		}
	}
	return (swapped);
}

/**
* backward_pass - to perform backward pass for cocktail sort algo
* @list: pointer to the head node ofl list
* @end: pointer to the end node of the current pass
* Return: 1 if a swap occured else 0
*/
int backward_pass(listint_t **list, listint_t *end)
{
	listint_t *current = end;
	int swapped = 0;

	while (current != *list)
	{
		if (current->n < current->prev->n)
		{
			/*swap nodes*/
			if (current->prev->prev != NULL)
				current->prev->prev->next = current;
			else
				*list = current;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev != NULL)
				current->prev->next = current;
			swapped = 1;
			print_list(*list);
		}
		else
		{
			current = current->prev;
		}
	}

	return (swapped);
}

/**
* cocktail_sort_list - Sorts a doubly linked list of integers in
* ascending order
* @list: Pointer to a pointer to the head node of the list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *end = NULL;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		swapped = forward_pass(list, end);
		if (!swapped)
			break;

		swapped = 0;
		end = *list;

		swapped = backward_pass(list, end);
	}
}
