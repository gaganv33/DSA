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

void postorder(Node *root);
void preorder(Node *root);
void inorder(Node *root);

int main(){
	Node *root = new Node(10);
	root->right = new Node(30);
	Node *leftSub = new Node(20);
	root->left = leftSub;
	leftSub->left = new Node(40);
	leftSub->right = new Node(50);
	
	cout << "Inorder traversal: ";
	inorder(root);
	cout << "\nPreorder traversal: ";
	preorder(root);
	cout << "\nPostorder traversal: ";
	postorder(root);	 
	return 0;
}
void inorder(Node *root){
	if(root != NULL){
		inorder(root->left);
		cout << (root->key) << " ";
		inorder(root->right);
	} 	
}
void preorder(Node *root){
	if(root != NULL){
		cout << (root->key) << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(Node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << (root->key) << " ";
	}
}
