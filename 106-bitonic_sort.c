#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two elements in the array.
 * @arr: The array.
 * @i: Index of the first element.
 * @j: Index of the second element.
 */
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
 * bitonic_merge - Recursively merge the bitonic sequences.
 * @arr: The array.
 * @low: Starting index of the subarray.
 * @nelemnt: Number of elements in the subarray.
 * @order: 1 for ascending order, 0 for descending order.
 */
void bitonic_merge(int *arr, int low, int nelemnt, int order)
{
    if (nelemnt > 1)
    {
        int mid = nelemnt / 2;

        printf("Merging [%i/%i] (%s):\n", nelemnt, nelemnt, order ? "UP" : "DOWN");
        print_array(arr + low, nelemnt);

        for (int i = low; i < low + mid; i++)
        {
            if ((arr[i] > arr[i + mid]) == order)
            {
                swap(arr, i, i + mid);
            }
        }

        bitonic_merge(arr, low, mid, order);
        bitonic_merge(arr, low + mid, mid, order);
    }
}

/**
 * bitonic_sort_recursive - Recursive function for Bitonic Sort.
 * @arr: The array.
 * @low: Starting index of the subarray.
 * @nelemnt: Number of elements in the subarray.
 * @order: 1 for ascending order, 0 for descending order.
 */
void bitonic_sort_recursive(int *arr, int low, int nelemnt, int order)
{
    if (nelemnt > 1)
    {
        int mid = nelemnt / 2;

        bitonic_sort_recursive(arr, low, mid, 1);
        bitonic_sort_recursive(arr, low + mid, mid, 0);

        bitonic_merge(arr, low, nelemnt, order);

        printf("Result [%i/%i] (%s):\n", nelemnt, nelemnt, order ? "UP" : "DOWN");
        print_array(arr + low, nelemnt);
    }
}

/**
 * bitonic_sort - Sorts an array of integers using Bitonic Sort.
 * @array: The array.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
    {
        return;
    }

    bitonic_sort_recursive(array, 0, size, 1);
}
