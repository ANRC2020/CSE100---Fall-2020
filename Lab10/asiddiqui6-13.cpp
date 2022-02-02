#include <iostream>
using namespace std;

int hv(int* arr, int k) {
	int counter = 0;
	int new_index;
	
	do {
	
		new_index = ( (k%13) + (counter * (1 + (k%11))) ) % 13; 
		counter++;
		
	} while(*(arr + new_index) != -10);
	
	return new_index;
}

int main() {
	int size  = 13;
	int input;
	int index;
	
	int *arr = new int[size];
	
	for(int i = 0; i < size; i++) {
		*(arr + i) = -10;
	}
	
	do {
		cin >> input;
		if(input == -1) {
			continue;
		}
		index = hv(arr, input);
		
		*(arr + index) = input;
				
	} while(input != -1);
	
	cout << "++++table printout++++\n";
	
	for(int i = 0; i < 13; i++) {
		if(*(arr + i) == -10) {
			cout << endl;
			continue;
		}
		
		input = *(arr + i);
		cout << input << endl;
	}
	
	cout << "++++searching++++\n";
	
	do {
		cin >> input;
		if(input == -2) {
			continue;
		}
		int i = 0;
		for(i = 0; i < 13; i++) {
			if(*(arr + i) == input) {
				cout << i << endl;
				break;
			}
		}
		
		if(*(arr + i) != input) {
			cout << "NOT_FOUND\n";
		}
		
	} while(input != -2);
	
	cout << "++++deleting++++\n";
	
	do {
		cin >> input;
		if(input == -2) {
			continue;
		}
		
		for(int i = 0; i < 13; i++) {
		
			if(*(arr + i) == input) {
				*(arr + i) = -1;
			}
		}
	
	} while(input != -3);
	
	cout << "++++table printout++++\n";
	
	for(int i = 0; i < 13; i++) {
		if(*(arr + i) == -1 || *(arr +i) == -10) {
			cout << endl;
			continue;
		}
		
		input = *(arr + i);
		cout << input << endl;
	}
	
	return 0;
}
