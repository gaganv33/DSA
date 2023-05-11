#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left ,*right;
	Node(int x){
		key = x;
		left = right = NULL;
	}
};

Node* insert(Node *root, int x);
void inorder(Node *root);
Node *insertIter(Node *root, int x);

int main(){
	Node *root = new Node(8);
	root->left = new Node(2);   	

	int x;
	cin >> x;
	cout << "Recursive Solution" << endl;
	root = insert(root, x);
	inorder(root);
	cout << endl;
	cout << "Iterative Solution" << endl;
	root = insertIter(root, x);
	inorder(root);
	return 0;
}

Node* insert(Node *root, int x){
	if(root == NULL){
		return new Node(x);
	}
	else if(root->key < x){
		root->right = insert(root->right, x);
	}
	else{
		root->left = insert(root->left, x);
	}
	return root;
}
void inorder(Node *root){
	if(root != NULL){
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}
Node *insertIter(Node *root, int x){
	Node *temp = new Node(x);
	if(root == NULL){
		return temp;
	}
	Node *cur = root;
	while(cur != NULL){
		if(cur->key == x){
			return root;
		}
		else if(cur->key < x && cur->right == NULL){
			cur->right = temp;
			return root;
		}
		else if(cur->key > x && cur->left == NULL){
			cur->left = temp;
			return root;
		}
		else if(cur->key < x){
			cur = cur->right;
		}	                 	
		else{
			cur = cur->left;
		}
	}
	return root;
}