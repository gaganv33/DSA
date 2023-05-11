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

vector<int> inorder(Node *root);
vector<int> preorder(Node *root);
vector<int> postorder(Node *root);

int main(){
	Node* root = new Node(10);
	root->right = new Node(30);
	Node *leftSub = new Node(20);
	root->left = leftSub;
	leftSub->left = new Node(40);
	leftSub->right = new Node(50);

	vector<int> a;
	a = inorder(root);	
	cout << "Inorder" << endl;
	for(auto x : a){
		cout << x << " ";
	}
	cout << endl;
	a = preorder(root);
	cout << "Preorder" << endl;
	for(auto x : a){
		cout << x << " ";
	}
	cout << endl;
	cout << "Postorder" << endl;
	a = postorder(root);
	for(auto x : a){
		cout << x << " ";
	}                        	
	cout << endl;
	return 0;
}

vector<int> inorder(Node *root){
	vector<int> a;
	if(root == NULL){
		return a;
	}
	stack<Node*> st;
	Node* cur = root;
	while(cur != NULL || st.empty() == false){
		while(cur != NULL){
			st.push(cur);
			cur = cur->left;
		}
		cur = st.top();
		st.pop();
		a.push_back(cur->data);
		cur = cur->right;
	}
	return a;
}
vector<int> preorder(Node *root){
	vector<int> a;
	if(root == NULL){
		return a;
	}
	stack<Node*> st;
	st.push(root);
	while(!st.empty()){
		Node *cur = st.top();
		a.push_back(cur->data);
		st.pop();
		if(cur->right != NULL){
			st.push(cur->right);			
		}                           	
		if(cur->left != NULL){
			st.push(cur->left);
		}
	}
	return a;
}
vector<int> postorder(Node *root){
	vector<int> a;
	if(root == NULL){
		return a;
	}
	stack<Node *> st1;
	stack<Node *> st2;
	st1.push(root);
	while(!st1.empty()){
		Node *cur = st1.top();
		st1.pop();
		st2.push(cur);
		if(cur->left != NULL){
			st1.push(cur->left);
		}
		if(cur->right != NULL){
			st1.push(cur->right);
		}
	}
	while(!st2.empty()){
		Node *cur = st2.top();
		st2.pop();
		a.push_back(cur->data);
	}
	return a;
}