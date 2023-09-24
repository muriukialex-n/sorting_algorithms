#include "sort.h"
/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
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
}
/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order.
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;

		swapped = 0;
		end = current;
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		start = current;
	}
}
