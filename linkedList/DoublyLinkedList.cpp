#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *prev;
	Node *next;
	Node(int x){
		data = x;
		prev = next = NULL;
	}
};

void traverse(Node *head);
Node *insertBegin(Node *head, int x);
Node *insertEnd(Node *head, int x);
Node *deleteBegin(Node *head);
Node *deleteEnd(Node *head);
int Count(Node *head);
Node *insertAfterKthNode(Node *head, int x, int pos);
Node *deleteKthNode(Node *head, int pos);

int main(){
	int n;
	cin >> n;
	
	Node *head = NULL;
	Node *tail = NULL;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		Node *temp = new Node(x);
		if(head == NULL){
			head = temp;
			tail = temp;			
		}
		else{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}
	
	//int y;
	//cin >> y;
	//head = insertBegin(head, y);	
	//head = insertEnd(head, y);
	//head = deleteBegin(head);
	//head = deleteEnd(head);
	int pos;
	cin >> pos;
	//head = insertAfterKthNode(head, y, pos);
	head = deleteKthNode(head, pos);
	traverse(head);
	
	return 0;
}
void traverse(Node *head){
	Node *cur = head;
	while(cur != NULL){
		cout << cur->data << " ";
		cur = cur->next;
	}
	return;
}

Node *insertBegin(Node *head, int x){
	Node *temp = new Node(x);
	if(head == NULL){
		return temp;
	}
	temp->next = head;
	head->prev = temp;
	return temp;
}
Node *insertEnd(Node *head, int x){
	Node *cur = head;
	Node *temp = new Node(x);
	if(head == NULL){
		return temp;
	}
	while(cur->next != NULL){
		cur = cur->next;
	}
	temp->prev = cur;
	cur->next = temp;
	return head;
}
Node *deleteBegin(Node *head){
	if(head == NULL){
		return NULL;
	}
	if(head->next == NULL){
		delete head;
		return NULL;
	}
	Node *temp = head;	
	head = head->next;
	delete temp;
	return head;
}
Node *deleteEnd(Node *head){
	if(head == NULL){
		return NULL;
	}
	if(head->next == NULL){
		delete head;
		return NULL;
	}
	Node *pre = head;
	Node *cur = head;
	while(cur->next != NULL){
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	delete cur;
	return head;	
}
int Count(Node *head){
	Node *cur = head;
	int count = 0;
	while(cur != NULL){
		count++;
		cur = cur->next;
	}
	return count;
}
Node *insertAfterKthNode(Node *head, int x, int pos){
	int count = Count(head);
	if(pos > count || pos < 0){
		return head;
	}
	if(pos == count){
		return insertEnd(head, x);
	}
	if(pos == 0){
		return insertBegin(head, x);
	}
	Node *cur = head;
	Node *temp = new Node(x);
	for(int i = 1; i < pos; i++){
		cur = cur->next;
	}
	temp->prev = cur;
	temp->next = cur->next;
	cur->next->prev = temp;
	cur->next = temp;
	return head;
}       
Node *deleteKthNode(Node *head, int pos){
	int count = Count(head);
	if(pos > count || pos < 0){
		return head;
	}
	if(pos == count){
		return head;
	}	
	if(pos == 0){
		return deleteBegin(head);
	}
	Node *pre = head;
	Node *cur = head;
	for(int i = 0; i < pos; i++){
		pre = cur; 
		cur = cur->next;
	}
	if(cur->next == NULL){
		return deleteEnd(head);
	}
	pre->next = cur->next;
	cur->next->prev = pre;
	delete cur;
	return head;
}	