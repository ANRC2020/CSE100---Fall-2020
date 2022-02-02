/*
refrenced quicksort pseudocode from the textbook and the c plus plus website for random integer function implementation
*/

#include <stdio.h>
#include <stdlib.h>

int n;

void swap(int i, int j, int* arr) {
	int temp = *(arr + i);
	*(arr + i) = *(arr + j);
	*(arr + j) = temp;
}

int Partition(int* arr, int p, int r) {
	int x = *(arr + r);
	int i = p - 1;
	
	//printf("Pivot: %d\n", x);
	
	for(int j = p; j < r ; j++) {
		if(*(arr + j) <= x) {
			i++;
			swap(i, j, arr);
		}
		/* 
		for(int k = p; k < r; k++) {
			printf("%d;", *(arr + k));
		}
		printf("\n");
		*/
	}	
	/*
	for(int j = p; j < r; j++) {
		printf("%d;", *(arr + j));
	}
	printf("\n\n");
	
	int oldVal = x;
	int newVal;
	
	for(int j = i + 1; j < r; j++) {
		newVal = *(arr + j);
		*(arr + j) = oldVal;
		oldVal = newVal;
	}
	*/
	swap(i + 1, r, arr);
	
	return (i + 1); 
}

int RPartition(int* arr, int p, int r) { 
	int i = (rand() % (r - p + 1)) + p; 
	//printf("random pivot: %d\n", *(arr + i) );   
	swap(r, i, arr);
	return Partition(arr, p, r);
}

void RQuicksort(int* arr, int p, int r) {
	if(p < r) {
		int q = RPartition(arr, p, r);
		RQuicksort(arr, p, q - 1);
		RQuicksort(arr, q + 1, r);   
	}	
}

int main() {
	
	scanf("%d", &n);
	
	int *arr = (int*)malloc(n*sizeof(int));
	
	for(int i = 0; i < n; i++) {
		scanf("%d", (arr + i));
	}
	
	RQuicksort(arr, 0, n - 1);
	
	for(int i = 0; i < n; i++) {
		printf("%d;", *(arr + i));
	}
	printf("\n");
	
	return 0;
}
