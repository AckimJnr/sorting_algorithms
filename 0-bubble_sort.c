#include "sort.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * bubble_sort - sorts an array using the bubble sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped = 0;

	i = 0, j = 0;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped <= 0)
			return;
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
