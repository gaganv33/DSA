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

bool searchReursive(Node *root, int x);
bool searchIterative(Node *root, int x);

int main(){
	Node *root = new Node(15);
	root->left = new Node(5);
	root->left->left = new Node(3);
	
	Node *rightSub = new Node(20);
	root->right = rightSub;
	rightSub->right = new Node(80);
	rightSub->left = new Node(18);
	rightSub->left->left = new Node(16);
	int x;
	cin >> x;
	
	cout << "Recursive Solution: " << searchReursive(root, x) << endl;
	cout << "Iterative Solution: " << searchIterative(root, x) << endl;
	return 0;
}

bool searchReursive(Node *root, int x){
	if(root == NULL){
		return false;
	}
	if(root->data == x){
		return true;
	}
	else if(root->data < x){
		return searchReursive(root->right, x);
	}
	else{
		return searchReursive(root->left ,x);
	}
}
bool searchIterative(Node *root, int x){
	if(root == NULL){
		return false;
	}
	Node *cur = root;
	while(cur != NULL){
		if(cur->data == x){
			return true;
		}
		else if(cur->data < x){
			cur = cur->right;
		}
		else{
			cur = cur->left;
		}
	}
	return false;
}