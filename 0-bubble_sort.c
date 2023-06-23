#include "sort.h"

/**
* bubble_sort - It prints a list of integers
* @array: a pointer to int array(unordered array)
* @size: the size of the array
*
* Return - Void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp = 0;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
