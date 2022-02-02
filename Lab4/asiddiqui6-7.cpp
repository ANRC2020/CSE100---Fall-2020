#include <stdio.h>

int MaxCrossingSubarray(int *arr, int low, int mid, int high) {
	
	//printf("Low: %d, Mid: %d, High: %d\n", low, mid, high);
	
	int leftsum = -2147483648, rightsum = -2147483648;
	int sum = 0;
	for(int i = mid; low <= i; i--) {
		sum = sum + *(arr + i);
		//printf("Value of *(arr+i): %d\n", *(arr + i)); 
		//printf("Value of sum (for leftsum): %d\n", sum); 
		if(sum > leftsum) {
			leftsum = sum;
		}
	}
	 
	sum = 0;
	for(int j = mid + 1; high >= j; j++) {  
		sum = sum + *(arr + j);
		//printf("Value of *(arr+j): %d\n", *(arr + j)); 
		//printf("Value of sum (for rightsum): %d\n", sum); 
		if(sum > rightsum) {
			rightsum = sum;
		}
	}
	
	//printf("\nMaxCrossing:\nleftsum = %d\nrightsum = %d\nleft+rightsum = %d\n\n", leftsum, rightsum, leftsum + rightsum);
	
	if(leftsum <= (leftsum + rightsum) && rightsum <= (leftsum + rightsum)) {
		return (leftsum + rightsum);
	} else if((leftsum + rightsum) <= leftsum && rightsum <= leftsum) {
		return leftsum;
	} else if((leftsum + rightsum) <= rightsum && leftsum <= rightsum){
		return rightsum;
	}
	
}

int MaxSubarraySum(int *arr, int low, int high) {
	if(high == low) {
		return *(arr + low);
	} else {
		int mid = (high + low)/2;
		
		int leftSum = MaxSubarraySum(arr, low, mid);
		//printf("leftSum value: %d\n", leftSum);
		int rightSum = MaxSubarraySum(arr, mid + 1, high);
		//printf("rightSum value: %d\n", rightSum);
		int crossSum = MaxCrossingSubarray(arr, low, mid, high);
		//printf("crossSum value: %d\n\n", crossSum);
		
		if(leftSum >= rightSum && leftSum >= crossSum) {
			return leftSum;
		} else if(rightSum >= leftSum && rightSum >= crossSum) {
			return rightSum;  
		} else {
			return crossSum; 
		}
	}	
		
}

int main() {
	int length, input;
	int *arr;
	
	scanf("%d", &length);
	
	for(int i = 0; i < length; i++) {
		scanf("%d", &input);
		*(arr + i) = input;
	}
	
	int result = MaxSubarraySum(arr, 0, length - 1);
	
	printf("%d", result);
	
	return 0;
}
