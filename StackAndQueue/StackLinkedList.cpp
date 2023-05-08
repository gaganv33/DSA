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
struct Stack{
	Node *head;
	int size;
	Stack(){
		head = NULL;
		size = 0;	 	
	}
	void push(int x){
		Node *temp = new Node(x);
		size++;
		if(head == NULL){
			head = temp;
 			return;	
		}
		temp->next = head;
		head = temp;
		return;
	}
	int pop(){
		if(head == NULL){
			return -1;
		}
		int res = head->data;
		Node *next = head->next;
		head = head->next;
		delete next;
		size--;
		return res;
	}
	int peek(){
		if(head == NULL){
			return -1;
		}
		return head->data;
	}
	int getSize(){
		return size;
	}
	bool isEmpty(){
		return (head == NULL);
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
	Stack s;
	s.push(5);
	s.push(15);
	s.push(25);
	s.print();
	cout << s.getSize() << endl;
	cout << s.peek() << endl;
	cout << s.pop() << endl;
	s.push(35);
	cout << s.peek() << endl;
	cout << s.isEmpty() << endl;
	return 0;
}