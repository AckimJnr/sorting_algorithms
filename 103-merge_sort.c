#include "sort.h"
#include <stdio.h>
/**
 * merge_sort - sorts an array using merge sort
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *B = (int *)malloc(size * sizeof(int));

	if (B == NULL)
		return;
	top_down_split_merge(B, 0, size, array);

	free(B);
}
/**
 * top_down_split_merge - recursively splits and merges sub arrays
 * @B: Temporal store of array elements
 * @iBegin: starting index of the current sub array
 * @iEnd: the ending index of the current subarary to be sorted
 * @A: the original sorted array
 *
 * Return: void
 */
void top_down_split_merge(int *B, size_t iBegin, size_t iEnd, int *A)
{
	size_t iMiddle;

	if (iEnd - iBegin <= 1)
		return;
	iMiddle = (iEnd + iBegin) / 2;
	top_down_split_merge(B, iBegin, iMiddle, A);
	top_down_split_merge(B, iMiddle, iEnd, A);
	top_down_merge(B, iBegin, iMiddle, iEnd, A);
}
/**
 * top_down_merge - merges two sorted sub arrays using top down algorithm
 * @B: Temporal store of array elements
 * @iBegin: starting index of the current sub array
 * @iMiddle: the ending index of the left sub array, start index of the right
 * @iEnd: the ending index of the current subarary to be sorted
 * @A: the original sorted array
 *
 * Return: void
 */
void top_down_merge(int *B, size_t iBegin, size_t iMiddle, size_t iEnd, int *A)
{
	size_t i = iBegin, j = iMiddle, k;

	printf("Merging...\n");
	printf("[left]: ");
	for (k = iBegin; k < iMiddle; k++)
	{
		printf("%d", A[k]);
		if (k != iMiddle - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (k = iMiddle; k < iEnd; k++)
	{
		if (k == iEnd - 1)
			printf("%d", A[k]);
		else
			printf("%d, ", A[k]);
	}
	printf("\n");
	for (k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
	}
	copy_array(B, iBegin, iEnd, A);
	printf("[Done]: ");
	for (k = iBegin; k < iEnd - 1; k++)
		printf("%d, ", A[k]);
	printf("%d\n", A[iEnd - 1]);
}
/**
 * copy_array - copy array a into b
 * @B: The destination array
 * @iBegin: starting index of the current sub array
 * @iEnd: the ending index of the current subarary to be sorted
 * @A: The source array
 *
 * Return: void
 */
void copy_array(int *A, size_t iBegin, size_t iEnd, int *B)
{
	size_t k;

	for (k = iBegin; k < iEnd; k++)
	{
		B[k] = A[k];
	}
}
