#include <stdio.h>
#include <cstdlib>

int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;

int len(int i) {
	switch(i) {
		case 0:
			return c0;
		case 1:
			return c1;
		case 2:
			return c2;
		case 3:
			return c3;
		case 4:
			return c4;
		case 5:
			return c5;
		case 6:
			return c6;
		case 7:
			return c7;
		case 8:
			return c8;
		case 9:
			return c9;	
	}
	return -9;
}

void sort(long double* arr, int i) {
	int size = len(i);
	
	if(size != 0) {
		
		for(int i = 1; i < size; i++) {
			if(*(arr + i) < *(arr + i - 1)) {
				for(int j = i;;j--) {
					if(*(arr + j) < *(arr + j - 1)) {
						double temp = *(arr + j);
						*(arr + j) = *(arr + j - 1);
						*(arr + j - 1) = temp;
					} else {
						break;
					}
				}
			}
			/*		
			for(int k = 0; k < size; k++) {
				printf("%.8Lf\n", *(arr + k));
			}
			*/
		}		
		
	}
}

void bucketsort(long double* arr, int n) {
	long double **B = (long double**)malloc(10*sizeof(long double*));
	
	for(int i = 0; i < n; i++) {
		
		if(0 <= *(arr + i) && *(arr + i) < .1) {
			c0++;
			long double *temp = (long double*)malloc(c0*sizeof(long double));
			
			for(int j = 0; j < c0; j++) {
				
				if(j == (c0 - 1)) {
					*(temp + j) = *(arr + i);
					break;
				}
				*(temp + j) = *(*(B + 0) + j);
			}	
			
			*(B + 0) = temp;
			/*
			for(int j = 0; j < c0; j++) {
				printf("%Lg\n", *(*(B + 0) + j));
			}			
			*/
		}
		
		if(0.1 <= *(arr + i) && *(arr + i) < .2) {
			c1++;
			long double *temp = (long double*)malloc(c1*sizeof(long double));
			
			for(int j = 0; j < c1; j++) { //c0 = 1, j = 0;
				
				if(j == (c1 - 1)) {
					*(temp + j) = *(arr + i);
					break;
				}
				*(temp + j) = *(*(B + 1) + j);
			}	
			
			*(B + 1) = temp;
			/*
			for(int j = 0; j < c1; j++) {
				printf("%Lg\n", *(*(B + 1) + j));
			}			
			*/
		}
		
		if(0.2 <= *(arr + i) && *(arr + i) < .3) {
			c2++;
			long double *temp = (long double*)malloc(c2*sizeof(long double));
			
			for(int j = 0; j < c2; j++) { //c0 = 1, j = 0;
				
				if(j == (c2 - 1)) {
					*(temp + j) = *(arr + i);
					break;
				}
				*(temp + j) = *(*(B + 2) + j);
			}	
			
			*(B + 2) = temp;
			/*
			for(int j = 0; j < c2; j++) {
				printf("%Lg\n", *(*(B + 2) + j));
			}			
			*/
		}
		
		if(0.3 <= *(arr + i) && *(arr + i) < .4) {
			c3++;
			long double *temp = (long double*)malloc(c3*sizeof(long double));
			
			for(int j = 0; j < c3; j++) { //c0 = 1, j = 0;
				
				if(j == (c3 - 1)) {
					*(temp + j) = *(arr + i);
					break;
				}
				*(temp + j) = *(*(B + 3) + j);
			}	
			
			*(B + 3) = temp;
			/*
			for(int j = 0; j < c3; j++) {
				printf("%Lg\n", *(*(B + 3) + j));
			}			
			*/
		}
		
		if(0.4 <= *(arr + i) && *(arr + i) < .5) {
			c4++;
			long double *temp = (long double*)malloc(c4*sizeof(long double));
			
			for(int j = 0; j < c4; j++) { //c0 = 1, j = 0;
				
				if(j == (c4 - 1)) {
					*(temp + j) = *(arr + i);
					break;
				}
				*(temp + j) = *(*(B + 4) + j);
			}	
			
			*(B + 4) = temp;
			/*
			for(int j = 0; j < c4; j++) {
				printf("%Lg\n", *(*(B + 4) + j));
			}			
			*/
		}
		
		if(0.5 <= *(arr + i) && *(arr + i) < .6) {
			c5++;
			long double *temp = (long double*)malloc(c5*sizeof(long double));
			
			for(int j = 0; j < c5; j++) { //c0 = 1, j = 0;
				
				if(j == (c5 - 1)) {
					*(temp + j) = *(arr + i);
					break;
				}
				*(temp + j) = *(*(B + 5) + j);
			}	
			
			*(B + 5) = temp;
			/*
			for(int j = 0; j < c5; j++) {
				printf("%Lg\n", *(*(B + 5) + j));
			}			
			*/
		}
		
		if(0.6 <= *(arr + i) && *(arr + i) < .7) {
			c6++;
			long double *temp = (long double*)malloc(c6*sizeof(long double));
			
			for(int j = 0; j < c6; j++) { //c0 = 1, j = 0;
				
				if(j == (c6 - 1)) {
					*(temp + j) = *(arr + i);
					break;
				}
				*(temp + j) = *(*(B + 6) + j);
			}	
			
			*(B + 6) = temp;
			/*
			for(int j = 0; j < c6; j++) {
				printf("%Lg\n", *(*(B + 6) + j));
			}			
			*/
		}
		
		if(0.7 <= *(arr + i) && *(arr + i) < .8) {
			c7++;
			long double *temp = (long double*)malloc(c7*sizeof(long double));
			
			for(int j = 0; j < c7; j++) { //c0 = 1, j = 0;
				
				if(j == (c7 - 1)) {
					*(temp + j) = *(arr + i);
					break;
				}
				*(temp + j) = *(*(B + 7) + j);
			}	
			
			*(B + 7) = temp;
			/*
			for(int j = 0; j < c7; j++) {
				printf("%Lg\n", *(*(B + 7) + j));
			}			
			*/
		}
		
		if(0.8 <= *(arr + i) && *(arr + i) < .9) {
			c8++;
			long double *temp = (long double*)malloc(c8*sizeof(long double));
			
			for(int j = 0; j < c8; j++) { //c0 = 1, j = 0;
				
				if(j == (c8 - 1)) {
					*(temp + j) = *(arr + i);
					break;
				}
				*(temp + j) = *(*(B + 8) + j);
			}	
			
			*(B + 8) = temp;
			/*
			for(int j = 0; j < c8; j++) {
				printf("%Lg\n", *(*(B + 8) + j));
			}			
			*/
		}
		
		if(0.9 <= *(arr + i) && *(arr + i) < 1) {
			c9++;
			long double *temp = (long double*)malloc(c9*sizeof(long double));
			
			for(int j = 0; j < c9; j++) { //c0 = 1, j = 0;
				
				if(j == (c9 - 1)) {
					*(temp + j) = *(arr + i);
					break;
				}
				*(temp + j) = *(*(B + 9) + j);
			}	
			
			*(B + 9) = temp;
			/*
			for(int j = 0; j < c9; j++) {
				printf("%Lg\n", *(*(B + 9) + j));
			}			
			*/
		}	
	
	}
	/*
	for(int i = 0; i < 10; i++) {
		int size = len(i);
		printf("Itteration: %d\n", i);
		for(int j = 0; j < size; j++) {
			printf("%Lg\n", *(*(B + i) + j));
		}
	}
	*/
	for(int i = 0; i < 10; i++) {
		sort(*(B + i), i);
	}
	
	int counter = 0;
	for(int i = 0; i < 10; i++) {
		int size = len(i);
		if(size != 0) {
			int j = 0;
			while(j < size) {
				*(arr + counter) = *(*(B + i) + j);
				j++;
				counter++;
			}			
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	long double *arr = (long double*)malloc(n*sizeof(long double));
	
	for(int i = 0; i < n; i++) {
		scanf("%Lf", (arr + i));
	}	
	
	bucketsort(arr, n);
	
	for(int i = 0; i < n; i++) {
		printf("%Lg\n", *(arr + i));
	}
	
	return 0;
}
