#include "sort.h"

/**
 * heap_sort - sorts an array following the Heap sort algorithm
 * @array: array of ints to sort
 * @size: size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int tmp;

	if (size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, (size_t)i, size);

	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		if (i != 0)
			print_array(array, size);
		heapify(array, (size_t)i, 0, size);
	}
}

/**
 * heapify - turns an array in a heap tree
 * @array: array to turn into heap
 * @s: size of the subtree
 * @root: index of the subtree in the heap
 * @size: size of the whole array
 */
void heapify(int *array, size_t s, size_t root, size_t size)
{
	size_t max, left, right;
	int tmp;

	max = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;

	if (left < s && array[left] > array[max])
		max = left;

	if (right < s && array[right] > array[max])
		max = right;

	if (max != root)
	{
		tmp = array[root];
		array[root] = array[max];
		array[max] = tmp;
		print_array(array, size);
		heapify(array, s, max, size);
	}
}
