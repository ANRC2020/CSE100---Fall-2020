#include <stdio.h>
#include <cstdlib> 

void shift(int x, int pos, int arrsize, int **arr) {
	/*
	printf("x value: %d\n", x);	
	
	printf("Before shift:\n");
	for(int i = 0; i < arrsize; i++) {
		for(int j = 0; j < 2; j++) {
			printf("%d;", *(*(arr+i)+j) );
		}
		printf("\n"); 
	}
	*/
	int *value = (int*)malloc(10*sizeof(int));
	
	//printf("Stored value: ");
	for(int i = 0; i < 10; i++) {
		*(value + i) = *(*(arr + x) + i);
		//printf("%d ", *(value + i));
	}
	//printf("\n");
	
	
	for(int i = x; 0 <= (i - pos); i--) {
	
		if(0 == (i - pos)) {
			//printf("Set value: ");
			for(int j = 0; j < 10; j++) {
				*(*(arr + i) + j) = *(value + j);
				//printf("%d ", *(*(arr + i) + j));
			}
			//printf("\n");
			break;
		}
		
		//printf("Shift to right: ");
		for(int j = 0; j < 10; j++) {
			*(*(arr + i) + j) = *(*(arr + i - 1) + j);
			//printf("%d ", *(*(arr + i) + j));
		}
		//printf("\n");
	
	}
	
	/*
	printf("After shift: \n");
	for(int i = 0; i < arrsize; i++) {
		for(int j = 0; j < 2; j++) {
			printf("%d;", *(*(arr+i)+j) );
		}
		printf("\n");
	}
	*/
}

void RadixSort(int **arr, int arrsize, int digit) {
	int *log = (int*)malloc((10)*sizeof(int));
	
	for(int i = 0; i < arrsize; i++) {
		*(log + *(*(arr+i)+digit)) += 1;
	}
	
	int pos = 0;
	
	for(int i = 0; i < 10; i++) {
	
		int x = 0;
		
		for(int j = 0; j < *(log + i); j++) {
		
			//printf("Value: %d, Quantity: %d\n", i, *(log + i));
			
			while(x < arrsize) {
			
				if(i == *(*(arr + x) + digit) ) {
				
					shift(x, pos, arrsize, arr);
					
					pos++;
					x++;
					break;
				}
				x++;
			}
			
			
			
		}
		
	}
	
	if(digit != 0) {
		//printf("\n\n");
		digit--;
		RadixSort(arr, arrsize, digit);
	}
		
}

int main() {
	int n;
	scanf("%d", &n);
	
	int** arr = (int**)malloc((n)*sizeof(int*));
	
	for(int i = 0; i < n; i++) {
		int *temp = (int*)malloc(10*sizeof(int)); //*temp = value at address, temp = address
		*(arr + i) = temp;
		for(int j = 0; j < 10; j++) {
			scanf("%d", (*(arr+i)+j) );
		}
	}
	/*
	printf("Original:\n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {
			printf("%d;", *(*(arr+i)+j) );
		}
		printf("\n");
	}
	printf("\n");
	*/
	RadixSort(arr, n, 9);
	
	//printf("\nAfter:\n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 10; j++) {
			printf("%d;", *(*(arr+i)+j) );
		}
		printf("\n");
	}
	
	return 0;
}

/*	//Log test
	printf("log stores:\n"); 
	for(int i = 0; i < 10; i++) {
		printf("Index: %d, Quantity: %d\n", i, *(log + i) );
	}
	printf("\n");
*/
