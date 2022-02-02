#include <iostream>
using namespace std;

int *r;
int *s;

void set_r_and_s(int n) {
	r = new int[n + 1];
	s = new int[n + 1];
}

void extendedbottomupcutrod(int *p, int n) {
	*(r + 0) = 0;
	int q;

	for(int j = 1; j <= n; j++) {
		q = -2147483648;

		for(int i = 1; i <= j; i++) {
			if(q < *(p + i) + *(r + j - i)) {
				q = *(p + i) + *(r + j - i);
				*(s + j) = i;
			}
		}

		*(r + j) = q;
	}

	int total = 0;
	int temp = n;

	while(temp > 0) {
		total += *(p + *(s + temp));
		temp = temp - *(s + temp);
	}

	cout << total << endl;

	while(n > 0) {
		cout << *(s + n) << " ";
		n = n - *(s + n); 
	}

	cout << "-1" << endl;
	
}

int main() {
	int n;
	int input;

	cin >> n;

	int *p = new int[n + 1];
	set_r_and_s(n);

	for(int i = 1; i <= n; i++) {
		cin >> input;
		*(p + i) = input;
	}

	extendedbottomupcutrod(p, n);

	return 0;
}