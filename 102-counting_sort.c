#include "sort.h"

/**
* counting_sort - function that sorts an array of integers in
* ascending order using the Counting sort algorithm
* @array: Pointer to the array of integers.
* @size: Size of the array
* Return: void
*/
void counting_sort(int *array, size_t size)
{
	int *count = NULL, k = 0, y = 0;
	unsigned int x = 1;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (; x < size; x++)
	{
		if (array[x] > k)
			k = array[x];
	}
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	for (y = 0; y <= k; y++)
		count[y] = 0;
	for (x = 0; x < size; x++)
		count[array[x]] += 1;
	for (y = 0; y < k; y++)
	{
		count[y + 1] += count[y];
		printf("%d, ", count[y]);
	}

	count[y + 1] += count[y];
	printf("%d\n", count[y + 1]);
	for (x = 0; x < size; x++)
	{
		y = count[array[x]] - 1;
		if (array[x] != array[y])
		{
			k = array[x];
			array[x] = array[y];
			array[y] = k;
		}
	}

	free(count);
}
