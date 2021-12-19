// insertion sort
#include <math.h>
#include <stdio.h>

// Navneet code goes here...

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// Function for printing the array.
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* Main Function */
int main()
{
	int arr[10];
    int arr_size;
    printf("\n===================================\n");
    printf("\tINSERTION SORTING!");
    printf("\n===================================\n");
    printf("\nEnter the size of the array : ");
    scanf("%d", &arr_size);

    printf("Enter the Array : ");
    for (int i = 0; i < arr_size; i++){
        scanf("%d", &arr[i]);
    }

	printf("Given array is : \n");
    printArray(arr, arr_size);
	insertionSort(arr, arr_size);
	printf("\nSorted array is : \n");
	printArray(arr, arr_size);
	return 0;
}
