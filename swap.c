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
