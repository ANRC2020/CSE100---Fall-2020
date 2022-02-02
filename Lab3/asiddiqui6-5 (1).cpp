#include <stdio.h>
#include <cstdlib>

int* merge(int *a1, int *a2, int size1, int size2) {
	/*
	printf("a1 includes: ");
		for(int x = 0; x < size1; x++)
			printf("%d ", *(a1 + x));
		printf("\n");
		
	printf("a2 includes: ");
		for(int x = 0; x < size2; x++) //size2
			printf("%d ", *(a2 + x));
		printf("\n");
	*/
	int *merged = (int*)malloc( (size1 + size2) * sizeof(int) );
	int *arr1 = (int*)malloc( (size1 + 1) * sizeof(int) );
	int *arr2 = (int*)malloc( (size2 + 1) * sizeof(int) );
	
	for(int x = 0; x <= size1; x++) {
		if(x == size1) {
			*(arr1 + x) = 2147483647;
			//printf("arr1 added: %d\n", *(arr1 + x));
			continue;
		}
		*(arr1 + x) = *(a1 + x);
		//printf("arr1 added: %d\n", *(arr1 + x));
	}
	
	for(int x = 0; x <= size2; x++) {
		if(x == size2) {
			*(arr2 + x) = 2147483647;
			//printf("arr2 added: %d\n", *(arr2 + x));
			continue;
		}
		*(arr2 + x) = *(a2 + x);
		//printf("arr2 added: %d\n", *(arr2 + x));
	}
	
	int i = 0, j = 0;
	
	for(int k = 0; k < (size1 + size2); k++) {
		//printf("arr1: %d and arr2: %d\n", *(arr1+i), *(arr2+j));
		if(*(arr1 + i) <= *(arr2 + j)) {
			*(merged + k) = *(arr1 + i);
			i++;
			//printf("i: %d and j: %d\n", i, j);
		} else {
			*(merged + k) = *(arr2 + j);
			j++;
			//printf("i: %d and j: %d\n", i, j);
		}
	}
	/*
	printf("\nmerged contains: ");
	for(int z = 0; z < (size1 + size2); z++)	
		printf("%d ", *(merged + z) );
	printf("\n");
	*/
	//Use calloc on merged, arr1, arr2, a1, a2 in mergesort
	return merged;
	
}

int* MergeSort(int* arr, int min, int max) {
	
	int mid = (min + max)/2;
	
	if(min < max) {
		int size1 = mid - min + 1;
		int size2 = max - mid;
		
		int *a1 = (int*)malloc(size1 * sizeof(int));
		a1 = MergeSort(arr, min, mid);
		
		 
		
		int *a2 = (int*)malloc(size2 * sizeof(int));
		a2 = MergeSort(arr , mid + 1, max);
		
		
		
		arr = merge(a1, a2, size1, size2);
		
	}
	  
	if(min == max) {
	int* single_val = (int*)malloc(1*sizeof(int));
	for(int i = 0; i < 1; i++) {
		int temp = *(arr + min);
		*single_val = temp;
	}
	//printf("Returning: %d\n", *(single_val));
	return single_val;
	}
	
	return arr; 
}


int main() {
	
	int length;
	scanf("%d", &length);
	
	int *arr = (int*)malloc(length * sizeof(int));
	
	for(int i = 0; i < length; i++) {
		scanf("%d", (arr + i));
	}
	
	arr = MergeSort(arr, 0, length - 1);
	
	for(int i = 0; i < length; i++) {
		printf("%d;", *(arr + i));
	}
	//printf("\n");
	
	return 0;
}
