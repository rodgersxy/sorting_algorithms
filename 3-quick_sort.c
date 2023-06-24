#include "sort.h"
/**
* swap_values - To swap 2 values in array of integers
* @array: Array of integers
* @idx1: value of first index
* @idx2: value of second index
* Return: Array value
*/
void swap_values(int **array, size_t idx1, size_t idx2)
{
	int temp;

	temp = (*array)[idx1];
	(*array)[idx1] = (*array)[idx2];
	(*array)[idx2] = temp;
}

/**
* partition - picks the pivot point in the array
* @array: Array to sort
* @low: lowest elements in the partition
* @high: highest
* @size: the size of the array
* Return: index of the partition
*/
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int pivot;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_values(&array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[high] < array[i])
	{
		swap_values(&array, i, high);
		print_array(array, size);
	}
	return (i);
}
/**
* _quick_sort - sort each partition of the array
* @array: Array to sort
* @low: lowest index of partition
* @high: highest index of th partition
* @size: size of array
*/
void _quick_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		_quick_sort(array, low, pivot - 1, size);
		_quick_sort(array, pivot + 1, high, size);
	}
}

/**
* quick_sort - quick sort array pf integers
* @array: Array of integers
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	ssize_t high = (size - 1);
	ssize_t low = 0;

	if (!array || size < 2)
		return;

	_quick_sort(array, low, high, size);
}
