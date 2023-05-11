#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

Node *getSuccessor(Node *root);
Node *deleteNode(Node *root, int x);
void inorder(Node *root);

int main(){
	Node *root = new Node(50);
	Node* rightSub = new Node(70);
	root->right = rightSub;
	rightSub->left = new Node(60);
	rightSub->right = new Node(80);
	Node* leftSub = new Node(30);
	root->left = leftSub;
	leftSub->left = new Node(20);
	leftSub->right = new Node(40);

	int x;
	cin >> x;	
	
	root = deleteNode(root, x);
	inorder(root);
	return 0;	
}

Node *deleteNode(Node *root, int x){
	if(root == NULL){
		return root;
	}
	if(root->data < x){
		root->right = deleteNode(root->right, x);
	}
	else if(root->data > x){
		root->left = deleteNode(root->left, x);
	}
	else{
		if(root->left == NULL){
			Node *temp = root->right;
			delete root;
			return temp;	        	
		}
		else if(root->right == NULL){
			Node *temp = root->left;
			delete root;
			return temp;
		}
		else{
			Node *suc = getSuccessor(root);
			root->data = suc->data;
			root->right = deleteNode(root->right, suc->data);			
		}
	}
	return root;
}
Node *getSuccessor(Node *root){
	root = root->right;
	while(root != NULL && root->left != NULL){
		root = root->left;
	}
	return root;
}
void inorder(Node *root){
	if(root != NULL){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}