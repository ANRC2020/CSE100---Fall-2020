#include <iostream>
using namespace std;

struct Link {
	int value = NULL;
	Link* next = NULL;
	
	Link() {
		value = NULL;
		Link* next = NULL;
	}
};

int main() {
	int length;
	cin >> length;
	
	Link *HT = new Link[length];
	
	string s;
	int n;

	do {
		cin >> s; 
		
		if(s == "e") {
			return 0;
		}
		
		if(s == "o") {
			for(int i = 0; i < length; i++) {
				cout << i << " : ";
				Link* pointer;
				pointer = HT[i].next;
				while(pointer != NULL) {
					cout << pointer->value;
					pointer = pointer->next;
					if(pointer != NULL) {
						cout << "->";
					}
				}
				cout << endl;
			}
			cout << "++++++++++++++++++++\n";
			continue;
		}
		
		cin >> n;
		
		if(s == "i") {
			
			Link *ptr = new Link();
			int index = n%length;
			ptr->next = HT[index].next;
			ptr->value = n;
			HT[index].next = ptr;
			continue;
			
		}
		
		if(s == "d") {
			int current;
			int index = n%length;
			Link *ptr1;
			ptr1 = (HT + index);
			Link *nptr1;
			nptr1 = ptr1->next;
			
			while(nptr1 != NULL) {
				current = nptr1->value;
				if(current == n) {
					break;
				}
				ptr1 = ptr1->next;
				nptr1 = nptr1->next;
			}
			
			if(current == n) {
				ptr1->next = nptr1->next;
				cout << current << " : DELETED\n";
			} else {
				cout << n << " : DELETE FAILED\n";
			}
		}
		
		if(s == "s") {
			int current;
			int counter = 0;
			int index = n%length;
			Link *ptr;
			ptr = (HT + index);
			Link *nptr;
			nptr = ptr->next;
			
			while(nptr != NULL) {
				current = nptr->value;
				if(current == n) {
					break;
				}
				counter++;
				ptr = ptr->next;
				nptr = nptr->next;
			}
			
			if(current == n) {
				cout << current << " : FOUND AT " << index << "," << counter << "\n";
			} else {
				cout << n << " : NOT FOUND\n";
			}
		}
		
		cout << "++++++++++++++++++++\n";
		
	} while(s != "e");
	
	return 0;
}
