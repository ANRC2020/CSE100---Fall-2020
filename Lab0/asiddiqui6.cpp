#include <stdio.h>

int main() {
	int arraySize = 0;
	
	scanf("%d", &arraySize);
	
	 int arr[arraySize];
	
	for(int i = 0; i < arraySize; i++){
		int temp = 0;
		scanf("%d", &temp);
		arr[i] = temp;
	}
	
	//printf("\n");
	
	for(int i = 1; i < arraySize; i++){
		int current = arr[i];
		
		for(int j = 0; j < i; j++){
		
			if(i == j || arr[j] < arr[i]) {
				continue;
			} else {
				
				for(int k = i; j < k; k--) {
					arr[k] = arr[k - 1];
				}
				arr[j] = current;
				
			}
	
		}
		
	}
	
	arraySize--;
	
	while(arraySize != -1) {
		printf("%d;",arr[arraySize]);
		arraySize--;
	}
	
	//printf("\n");
	
return 0;
}

