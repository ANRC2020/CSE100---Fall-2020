#include<iostream> 
using namespace std;

int n = 0;

int printopt(int** s, int i, int j) {
	if(i == j) {
		int temp = i - 1;
		cout << "A" << temp;
	} else {
		cout << "(";
		printopt(s, i, *(*(s + i) + j) );
		printopt(s, *(*(s + i) + j) + 1, j);
		cout << ")";
	}
}
 
void MatrixChainOrder(int* p) {
	
	int** m = new int*[n];
	int** s = new int*[n - 1];

    for(int i = 0; i < n; i++) {
    	*(m + i) = new int[n];
    }
 	
    for(int i = 0; i < n; i++) {
    	*(s + i) = new int[n];
    } 

    for (int i = 1; i < n; i++) {
        *(*(m + i) + i) = 0;
    }
 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {

            int j = i + L - 1;
            *(*(m + i) + j) = 2147483647;
 
            for (int k = i; k <= j - 1; k++) {
                int q = *(*(m + i) + k) + *(*(m + k + 1) + j) + (*(p + i - 1))*(*(p + k))*(*(p + j));
                if (q < *(*(m + i) + j) ) {
                    *(*(m + i) + j) = q;
                    *(*(s + i) + j) = k;
                }
            }
        }
    }
 	
 	cout << *(*(m + 1) + n - 1) << endl;
    printopt(s, 1, n - 1);
}
 
int main() {
    cin >> n;
  
    int* arr = new int[n + 1];
 
    for(int i = 0; i < n + 1; i++) {
        cin >> *(arr + i);
    }
 	
 	n++;
    
    MatrixChainOrder(arr);
 
    return 0;
}