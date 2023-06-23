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
	int tmp = 0, i, x;

	for (i = size - 2; i >= 0; i--)
	{
		for (x = 0; x <= i; x++)
		{
			if (array[x] > array[x + 1])
			{
				tmp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
