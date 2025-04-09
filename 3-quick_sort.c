#include "sort.h"

/**
 * swap - swaps two integers in an array and prints the array
 * @array: the array containing the integers
 * @size: the size of the array
 * @a: pointer to the first integer to swap
 * @b: pointer to the second integer to swap
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b) /* Vérifie si les valeurs sont différentes */
	{
		int temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size); /* Affiche le tableau après l'échange */
	}
}

/**
 * lomuto_partition - partitions the array using the Lomuto scheme
 * @array: array to be partitioned
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: index of the pivot after partitioning
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high]; /* Le pivot est le dernier élément */
	int i = low - 1; /* Index du plus petit élément */
	int j;
	int temp;

	/* Parcourt tous les éléments et compare avec le pivot */
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++; /* Incrémente l'index du plus petit élément */
			if (i != j) /* Échange si nécessaire */
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size); /* Affiche après l'échange */
			}
		}
	}

	/* Place le pivot à sa position finale correcte */
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size); /* Affiche après l'échange du pivot */
	}

	return (i + 1); /* Retourne la position du pivot */
}


/**
 * quick_sort_recursive - implements the quicksort algorithm recursively
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	if (low < high) /* Condition d'arrêt de la récursion */
	{
		/* Trouve la position du pivot et partitionne le tableau */
		int pivot = lomuto_partition(array, size, low, high);

		/* Trie récursivement les deux sous-tableaux */
		quick_sort_recursive(array, size, low, pivot - 1); /* Sous-tableau gauche */
		quick_sort_recursive(array, size, pivot + 1, high); /* Sous-tableau droit */
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2) /* Vérifie les cas de base */
		return;

	quick_sort_recursive(array, size, 0, size - 1); /* Lance le tri récursif */
}
