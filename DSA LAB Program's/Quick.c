// Quick Sorting...
#include <stdio.h>
#include <stdlib.h>

// Navneet code goes here...

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[10];
    int arr_size;
    printf("\n==============================\n");
    printf("\tQUICK SORTING!");
    printf("\n==============================\n");
    printf("\nEnter the size of the array : ");
    scanf("%d", &arr_size);

    printf("Enter the Array : ");
    for (int i = 0; i < arr_size; i++){
        scanf("%d", &arr[i]);
    }

    printf("Given array is : \n");
    printArray(arr, arr_size);
	quickSort(arr, 0, arr_size - 1);
	printf("Sorted array: \n");
	printArray(arr, arr_size);
	return 0;
}

