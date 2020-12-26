#include <stdio.h> 
void selectionSort(int arr[], int n) 
{ 
	int i, j, key, temp; 

	for (i = 0; i < n-1; i++) 
	{ 
		key = i; 
		for (j = i+1; j < n; j++) 
		{
			if (arr[j] < arr[key]) 
				key = j; 
		}
		temp = arr[key];
		arr[key] = arr[i];
		arr[i] = temp;
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = {64, 25, 12, 22, 11, 45, 3, 6, 9}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	selectionSort(arr, n); 
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	return 0; 
} 
