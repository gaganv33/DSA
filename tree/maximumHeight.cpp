#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left;
	Node *right;
	Node(int k){
		key = k;
		left = NULL;
		right = NULL;
	}
};

int maxHeight(Node *root);

int main(){
	Node *root = new Node(10);
	root->left = new Node(8);
	root->right = new Node(30);
	root->left->right = new Node(40);
	root->left->left = new Node(50);
	root->left->left->right = new Node(70);
	cout << maxHeight(root) << endl;
	return 0;
}

int maxHeight(Node *root){
	if(root == NULL){
		return 0;
	}
	return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}