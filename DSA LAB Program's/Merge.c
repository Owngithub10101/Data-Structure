// Merge sorting...
#include <stdio.h>
#include <stdlib.h>

// Navneet code goes here...

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int x = m - l + 1;
	int y = r - m;
	int L[10], R[10];
	for (i = 0; i < x; i++)
		L[i] = arr[l + i];
	for (j = 0; j < y; j++)
		R[j] = arr[m + 1 + j];

	i = 0; j = 0; k = l; 
	while (i < x && j < y) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < x) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < y) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
// Merge sort function.
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
// Display Array.
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int arr[10];
    int arr_size;
    printf("\n==============================\n");
    printf("\tMERGE SORTING!");
    printf("\n==============================\n");
    printf("\nEnter the size of the array : ");
    scanf("%d", &arr_size);

    printf("Enter the Array : ");
    for (int i = 0; i < arr_size; i++){
        scanf("%d", &arr[i]);
    }

	printf("Given array is : \n");
	printArray(arr, arr_size);
	mergeSort(arr, 0, arr_size - 1);
	printf("\nSorted array is : \n");
	printArray(arr, arr_size);
	return 0;
}
