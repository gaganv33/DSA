#include<bits/stdc++.h>
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

struct Deque{
	Node *head;
	Node *tail;
	int size;
	Deque(){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insertFront(int x){
		size++;
		Node *temp = new Node(x);
		if(head == NULL){
			head = tail = temp;
			return;
		}
		temp->next = head;
		head->prev = temp;
		head = temp;
		return;
	}
	void insertRear(int x){
		size++;
		Node *temp = new Node(x);
	        if(head == NULL){
	        	head = tail = temp;
			return;
		}
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		return;
	}
	int deleteFront(){
		if(head == NULL){
			return INT_MIN;
		}
		if(head == tail){
			int res = head->data;
			size = 0;
			delete head;
			head = NULL;
			tail = NULL;
			return res;
		}
		Node *next = head;
		int res = head->data;
		head = head->next;
		delete next;
		size--;
		return res;
	}
	int deleteRear(){
		if(head == NULL){
			return INT_MIN;
		}
		if(head == tail){
	        	int res = head->data;
			size = 0;
			delete head;
			head = NULL;
			tail = NULL;
			return res;
		}
		int res = tail->data;
		Node *next = tail;
		tail->prev->next = NULL;
		tail = tail->prev;
		size--;
		delete next;
		return res;                     	
	}
	int getFront(){
		return head->data;
	}
	int getRear(){
		return tail->data;
	}
	int getSize(){
		return size;
	}
	bool isEmpty(){
		return (size == 0);
	}
	void print(){
		if(head == NULL){
			return;
		}
		Node *cur = head;
		while(cur != NULL){
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
		return;
	}
};

int main(){
	Deque q;
	q.insertFront(10);
	q.insertFront(20);
	q.insertFront(30);
	q.insertFront(40);
	q.print();
	cout << q.getFront() << endl;
	cout << q.getRear() << endl;
	cout << q.getSize() << endl;
	cout << q.deleteFront() << endl;
	cout << q.deleteRear() << endl;
	q.print();
	cout << q.isEmpty() << endl;
	cout << q.getSize() << endl;
	return 0;
}