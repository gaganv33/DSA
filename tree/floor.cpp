#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		data = x;
		left = right = NULL;
	}
};

int FloorValue(Node *root, int x);

int main(){
	Node *root = new Node(10);
	root->left = new Node(5);
	Node *rightSub = new Node(15);
	root->right = rightSub;
	rightSub->left = new Node(12);
	rightSub->right = new Node(30);

	int x;
	cin >> x;
	int value = FloorValue(root, x);
	cout << value << endl;
	
	return 0;
}

int FloorValue(Node *root, int x){
	if(root == NULL){
		return INT_MIN;
	}
	
	int res = INT_MIN;
	Node *cur = root;
	while(cur != NULL){
		int value = cur->data;
		if(value < x && value > res){
	        	res = value;
		}
		else if(value == x){
			return x;
		}
		else if(value < x){
	        	cur = cur->right;
		}
		else{
			cur = cur->left;
		}
	}
	return res;
}