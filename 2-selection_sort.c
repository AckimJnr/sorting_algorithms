#include "sort.h"
/**
 * selection_sort - sorts an array using selection sort
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Returns void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min_item_index = 0;
	int is_sorted = 0;

	if (array == NULL || size < 2)
		return;

	while (i < size - 1)
	{
		min_item_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_item_index])
			{
				min_item_index = j;
				is_sorted = 1;
			}
		}
		if (is_sorted < 1)
			return;
		if (min_item_index != i)
			swap(&array[i], &array[min_item_index]);
		print_array(array, size);
		i++;
	}
}
/**
 * swap - swaps integers
 * @a: first integer
 * @b: second integer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	if (*a == *b)
		return;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
