#include<stdio.h>
#include<stdlib.h>

int main() {
	int length = 0;
	int search = 0;
	scanf("%d", &length);
	int* arr = (int*)malloc(length * sizeof(int)); //new int[length];
	scanf("%d", &search);
	
	for(int i = 0; i < length; i++){
		scanf("%d", (arr + i));
	}
	
	//printf("Size of array: %d", length);
	//printf("Search number: %d", search);
	
	for(int i = 0; i < length; i++){
		if(search == *(arr + i)){
			printf("%d", i);
			return 0;
		}
	}
	printf("%d", -1);
	return 0;
}
