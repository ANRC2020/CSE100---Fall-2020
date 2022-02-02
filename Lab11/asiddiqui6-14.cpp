#include <iostream>
using namespace std;

struct Node {
	Node *right;
	Node *left;
	int data;
	
	Node() {
		Node *right = NULL;
		Node *left = NULL;
		int data = NULL;
	}
};

void insert(Node *in, Node *ptr) {
	if(ptr->data == NULL) {
		ptr->data = in->data;
	} else {
		if(ptr->data <= in->data) {
			if(ptr->right != NULL) {
				ptr = ptr->right;
				insert(in, ptr);
			} else {
				ptr->right = in;				
			}
		} else {
			if(ptr->left != NULL) {				
				ptr = ptr->left;
				insert(in, ptr);
			} else {
				ptr->left = in;
			}
		}
	}
}

void inorder(Node *ptr) {
	if(ptr->right == NULL && ptr->left == NULL) {
		cout << ptr->data << "\n";
	} else {
		if(ptr->left != NULL) {
			inorder(ptr->left);
		}
		cout << ptr->data << "\n";
		if(ptr->right != NULL) {
			inorder(ptr->right);
		}		
	}	
}

void preorder(Node *ptr) {
	if(ptr->left == NULL && ptr->right == NULL) {
		cout << ptr->data << "\n";
	} else {
		cout << ptr->data << "\n";
		if(ptr->left != NULL) {
			preorder(ptr->left);
		}
		if(ptr->right != NULL) {
			preorder(ptr->right);
		} 
	}
}

void postorder(Node *ptr) {
	if(ptr->right == NULL && ptr->left == NULL) {
		cout << ptr->data << "\n";
	} else {
		if(ptr->left != NULL) {
			postorder(ptr->left);
		}
		if(ptr->right != NULL) {
			postorder(ptr->right);
		}	
		cout << ptr->data << "\n";	
	}	
}

int del(Node *ptr, Node *prev, int num) {
	if((ptr->left == NULL && ptr->right == NULL) || (ptr->data == num)) {
		if((ptr->left == NULL && ptr->right == NULL) && (ptr->data != num)) {
			return 1;
		}
		if(ptr->left != NULL && ptr->right != NULL) {
			Node *max;
			Node *maxprev;
			maxprev = ptr;
			max = ptr->right;
			
			while(max->left != NULL) {
				maxprev = max;
				max = max->left;		
			}
			
			if(max->right != NULL) {
				if(maxprev->right == max) {
					maxprev->right = max->right;
				} else {
					maxprev->left = max->right;
				}
			} else {
				if(maxprev->right == max) {
					maxprev->right = NULL;
				} else {
					maxprev->left = NULL;
				}
			}
			
			ptr->data = max->data;
			return 0;
			
		} else if(ptr->left != NULL && ptr->right == NULL) {
			if(prev != NULL) {
				if(prev->left == ptr) {
					prev->left = ptr->left;
					return 0;
				}
				if(prev->right == ptr) {
					prev->right = ptr->left;
					return 0;
				}
			} else {
				prev = ptr;
				ptr = ptr->left;
				prev->data = ptr->data;
				prev->right = ptr->right;
				prev->left = ptr->left;
				return 0;
			}
		} else if(ptr->right != NULL && ptr->left == NULL) {
			if(prev != NULL) {
				if(prev->left == ptr) {
					prev->left = ptr->right;
					return 0;
				}
				if(prev->right == ptr) {
					prev->right = ptr->right;
					return 0;
				}
			} else {
				prev = ptr;
				ptr = ptr->right;
				prev->data = ptr->data;
				prev->right = ptr->right;
				prev->left = ptr->left;
				return 0;
			}
		} else {
			if(prev != NULL) {
				if(prev->left == ptr) {
					prev->left = NULL;
					return 0;
				} 
				if(prev->right == ptr){
					prev->right = NULL;
					return 0;
				}
			} else {
				ptr->data = NULL;
				return 0;
			}
		}
	} else {
		if(ptr->left != NULL && num < ptr->data) {
			prev = ptr;
			ptr = ptr->left;
			return del(ptr, prev, num);
		} else if(ptr->right != NULL && num > ptr->data) {
			prev = ptr;
			ptr = ptr->right;
			return del(ptr, prev, num);
		} else {
			return 1;
		}
	}
}

int main() {
	Node *root = new Node();
	string op;
	int input;
	
	do {
		cin >> op;
		
		if(op == "e") {
			continue;
		}
		
		if(op == "pre") {
			Node *ptr;
			ptr = root;
			
			preorder(ptr);
			cout << "++++++++++++++++++++\n";
			continue;
		}
		
		if(op == "post") {
			Node *ptr;
			ptr = root;
			
			postorder(ptr);
			cout << "++++++++++++++++++++\n";
			continue;
		}
		
		if(op == "in") {
			Node *ptr;
			ptr = root;
			
			inorder(ptr);
			cout << "++++++++++++++++++++\n";
			continue;
		}
		
		cin >> input;
		
		if(op == "i") {
			Node *in = new Node();
			in->data = input;
			
			Node *ptr;
			ptr = root;
			
			insert(in, ptr);
			continue;
		}
		
		if(op == "d") {
			Node *ptr;
			ptr = root;
			Node *prev;
			prev = NULL;
			
			int result = del(ptr, prev, input);
			/*
			if(result == 0) {
				cout << "DELETED " << input << endl;
			} else {
				cout << "DELETE FAILED\n";
			}
			*/
			continue;
		}
		
		cout << "++++++++++++++++++++\n";
	
	} while(op != "e");
	
	return 0;
}
/*
	Node *max;
	Node *maxprev;
	maxprev = ptr;
	max = ptr->left;
	
	while(max->right != NULL) {
		maxprev = max;
		max = max->right;		
	}
	
	if(max->left != NULL) {
		if(maxprev->left == max) {
			maxprev->left = max->left;
		} else {
			maxprev->right = max->left;
		}
	} else {
		if(maxprev->left == max) {
			maxprev->left = NULL;
		} else {
			maxprev->right = NULL;
		}
	}
	
	ptr->data = max->data;
	return 0;
*/
