#include "sort.h"
/**
* shell_sort - sorts array of integers in ascending
* order using shell sort algorith and knuth sequence
* @array: Array to be sorted
* @size: The size of the array
* Return: Nothing
*/
void shell_sort(int *array, size_t size)
{
	unsigned int interval = 1;
	unsigned int i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/*calculates knuth sequence*/
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval >= 1)
	{
		/* Perform insertion sort for the current interval */
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
		print_array(array, size);

		interval = (interval - 1) / 3;
	}
}
