#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int x){
		data = x;
		next = NULL;		
	}
};

struct Queue{
	Node* head;
	Node* tail;
	int size;
	Queue(){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void enqueue(int x){
		Node *temp = new Node(x);
		size++;
		if(head == NULL){
			head = tail = temp;
			return;	
		}
		tail->next = temp;
		tail = temp;
		return;
	}              	
	int dequeue(){
		if(head == NULL){
			return INT_MIN;
		}
		int res = head->data;
		if(head == tail){
			delete head;
			head = tail = NULL;
			size = 0;
			return res;
		}
		Node *next = head;
		head = head->next;
		delete next;
		size--;
		return res;
	}
	int getFront(){
		return (head->data);
	}
	int getRear(){
		return (tail->data);
	}
	int getSize(){
		return size;
	}
	bool isEmpty(){
		return (size == 0);
	}
	void print(){
		Node *cur =head;
		while(cur != NULL){
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
		return;
	}
};

int main(){
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.print();
	q.enqueue(30);	
	q.print();
	cout << q.dequeue() << endl;
	return 0;	
}
