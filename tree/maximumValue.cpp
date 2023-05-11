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


int maxValue(Node *root);

int main(){
	Node *root = new Node(30);
	root->left = new Node(20);
	root->left->left = new Node(40);
	cout << maxValue(root) << endl;
	return 0;
}


int maxValue(Node *root){
	if(root == NULL){
		return INT_MIN;
	}
	int Max = max(maxValue(root->left), root->key);
	return max(Max, maxValue(root->right));
}