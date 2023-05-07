#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
	Node(int x){
		data = x;
		next = NULL;
		prev = NULL;
	}
};

void traversal(Node *head);
Node *insertBegin(Node *head, int x);
Node *insertEnd(Node *head, int x);
Node *deleteBegin(Node *head);
Node *deleteEnd(Node *head);
int Count(Node *head);
Node *insertKthPos(Node *head, int x, int pos);
Node *deleteKthPos(Node *head, int pos);

int main(){
	Node *head = NULL;	
	Node *tail = NULL;
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		Node *temp = new Node(x);
		if(head == NULL){
			temp->next = temp->prev = temp;
			head = temp;
			tail = temp;
		}
		else{
			tail->next = temp;
			temp->prev = tail;
			temp->next = head;
			head->prev = temp;
			tail = temp;
		}
	}      
	int y;
	cin >> y;
	//head = insertBegin(head, y);	
	//head = insertEnd(head, y);
	//head = deleteBegin(head);
	//head = deleteEnd(head);
	int pos;
	cin >> pos;
	head = insertKthPos(head, y, pos);
	traversal(head);
	cout << endl;
	head = deleteKthPos(head, pos);
	traversal(head);
	return 0;
}
void traversal(Node *head){
	if(head == NULL){
		return;
	}
	Node *cur = head;
	do{
		cout <<	cur->data << " ";
		cur = cur->next;
	}while(cur != head);
	return;
}
Node *insertBegin(Node *head, int x){
	Node *temp = new Node(x);
	if(head == NULL){
		temp->next = temp->prev = temp;
		return temp;
	}
	temp->prev = head->prev;
	temp->next = head;
	head->prev->next = temp;
	head->prev = temp;
	return temp;
}
Node *insertEnd(Node *head, int x){
	Node *temp = new Node(x);
	if(head == NULL){
		temp->next = temp->prev = temp;
		return temp;
	}
	temp->next = head;
	temp->prev = head->prev;
	head->prev->next = temp;
	head->prev = temp;
	return head;
}
Node *deleteBegin(Node *head){
	if(head == NULL){
		return NULL;
	}
	if(head->next == head){
		delete head;
		return NULL;
	}
	Node *temp = head;
	head->prev->next = head->next;
	head->next->prev = head->prev;
	head = head->next;
	delete temp;	
	return head;
}
Node *deleteEnd(Node *head){
	if(head == NULL){
		return NULL;
	}
	if(head->next == head){
		delete head;
		return NULL;
	}
	Node *tail = head->prev;
	tail->prev->next = tail->next;
	tail->next->prev = tail->prev;	
	delete tail;
	return head;
}
int Count(Node *head){
	if(head == NULL){
		return 0;
	}
	int count = 0;
	Node *cur = head;
	do{
		count++;
		cur = cur->next;	
	}while(cur != head);
	return count;
}
Node *insertKthPos(Node *head, int x, int pos){
	int count = Count(head);
	if(pos == 0 && head == NULL){
		return insertBegin(head, x);
	}
	if(pos < 0 || pos >= count || (pos > 0 && head == NULL)){
		return head;
	}
	Node *temp = new Node(x);	                       
	Node *cur = head;
	for(int i = 0 ; i < pos; i++){
		cur = cur->next;
		if(cur == head){
			return insertEnd(head, x);
		}
	}
	temp->prev = cur;
	temp->next = cur->next;
	cur->next->prev = temp;
	cur->next = temp;
	return head;
}
Node *deleteKthPos(Node *head, int pos){
	if(head == NULL){
		return NULL;
	}
	int count = Count(head);
	if(pos < 0 || pos >= count){
		return head;
	}
	if(pos !=0 && head->next == head){
		return head;
	}
	if(pos == 0){
		return deleteBegin(head);
	}
	Node *cur = head;
	Node *pre = head;
	for(int i = 0; i < pos; i++){
		pre = cur;
		cur = cur->next;
	}
	cur->next->prev = pre;
	pre->next = cur->next;
	delete cur;
	return head;
}