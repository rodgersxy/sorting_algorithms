#include "sort.h"
/**
* selection_sort - function that sorts an array of integers
* in ascending order using the Selection sort algorithm
* @array: Array to sort
* @size: size of array
* Return: Void
*/
void selection_sort(int *array, size_t size)
{
	size_t x = 0, y = 0, midIndex = 0;
	int temp = 0;

	if (array == NULL || size == 0)
		return;

	for (x = 0; x < size - 1; x++)
	{
		midIndex = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[midIndex])
				midIndex = y;
		}
		if (midIndex != x)
		{
			temp = array[x];
			array[x] = array[midIndex];
			array[midIndex] = temp;
			print_array(array, size);
		}
	}
}
