#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int length = 0;
	scanf("%d", &length);
	int search = 0;
	scanf("%d", &search);
	
	int *num = (int*)malloc(length * sizeof(int));
	
	for(int i = 0; i < length; i++ ) {
		scanf("%d", (num + i));	
	}
	
	bool found = false;
	
	int mid1 = length/2;
	int mid2 = 0;
	if(length%2 == 1) {
		mid2 = mid1 + 1;
	} else {
		mid2 = mid1;
	}
	
	int min = 0;
	int max = length;
		
	while(found == false) {
	
		if(search <= *(num + mid1)) {
			max = mid1;
			mid1 = (max + min)/2;
			if((max + min)%2 == 1) {
				mid2 = mid1 + 1;
			} else {
				mid2 = mid1;
			}
			
		} else {
			min = mid2;
			mid1 = (max + min)/2;
			if((max + min)%2 == 1) {
				mid2 = mid1 + 1;
			} else {
				mid2 = mid1;
			}	
							
		}
		
		if(min == max && *(num + min) == search){
			printf("%d", min);
			found = true;
			continue;
		} 
		if(min == max && *(num + min) != search){
			printf("-1");
			found = true;
			continue;
		}
		
		
		//printf("Current min: %d and max: %d", min, max);
		//printf("\n");
		continue;
		
	}
	
	return 0;
}
