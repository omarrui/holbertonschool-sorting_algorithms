#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;

		/* Déplacer le nœud actuel vers sa position correcte */
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			insert = temp->prev;

			/* Mettre à jour les pointeurs next */
			if (temp->next != NULL)
				temp->next->prev = insert;
			insert->next = temp->next;
			temp->next = insert;

			/* Mettre à jour les pointeurs prev */
			temp->prev = insert->prev;
			insert->prev = temp;

			/* Mettre à jour la tête si nécessaire */
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			print_list(*list);
		}
	}
}

