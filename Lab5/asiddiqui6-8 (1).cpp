#include <stdio.h>
#include <cstdlib>  

void swap(int i, int j, int *arr) {

	int temp = *(arr + i);
	*(arr + i) = *(arr + j);
	*(arr + j) = temp;
	
}

void heapify(int *arr, int n, int i) {

	int largest = i;
	int L = 2*i + 1;
	int R = 2*i + 2;
	 
	if(L < n && *(arr + L) > *(arr + largest)) {
		largest = L;
	}
	
	if(R < n && *(arr + R) > *(arr + largest)) {
		largest = R;
	}
	
	if(largest != i) {
		swap(i, largest, arr); 
		heapify(arr, n, largest);
	}
	
}

void buildheap(int *arr, int n) {

	for (int i = n / 2 - 1; i >= 0; i--) {
        	heapify(arr, n, i); 
        }
        
} 

void heapsort(int *arr, int n) {
	
	buildheap(arr, n); 
	
	for (int i=n-1; i>0; i--) {
		swap(0, i, arr); 
		heapify(arr, i, 0); 
	} 
	
}

int main(){
  	int n = 0;
  	scanf("%d",&n);

  	int *arr = (int*)malloc(n*sizeof(int));
  
  	for(int i = 0; i < n; i++){
    		scanf("%d", (arr + i));
  	}

  	heapsort(arr, n);

  	for(int i = 0; i < n; i++){
    		printf("%d;",*(arr + i));
  	}
  	printf("\n");

  	return 0;
}
/*
#include <stdio.h>
#include <cstdlib>  

void swap(int i, int j, int arr[]) {

	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	
}

void heapify(int arr[], int n, int i) {

	int largest = i;
	int L = 2*i + 1;
	int R = 2*i + 2;
	 
	if(L < n && arr[L] > arr[largest]) {
		largest = L;
	}
	
	if(R < n && arr[R] > arr[largest]) {
		largest = R;
	}
	
	if(largest != i) {
		swap(i, largest, arr); 
		heapify(arr, n, largest);
	}
	
}

void buildheap(int arr[], int n) {

	for (int i = n / 2 - 1; i >= 0; i--) {
        	heapify(arr, n, i); 
        }
        
} 

void heapsort(int arr[], int n) {
	
	buildheap(arr, n); 
	
	for (int i=n-1; i>0; i--) {
		swap(0, i, arr); 
		heapify(arr, i, 0); 
	} 
	
}

int main(){
  	int n = 0;
  	scanf("%d",&n);

  	int arr[n];
  
  	for(int i = 0; i < n; i++){
    		scanf("%d", &arr[i]);
  	}

  	heapsort(arr, n);

  	for(int i = 0; i < n; i++){
    		printf("%d;", arr[i]);
  	}
  	printf("\n");

  	return 0;
}

*/
