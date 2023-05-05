#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};
typedef struct Node node;

void traversal(node *head);
node *insertBegin(node *head, int x);
node *insertEnd(node *head, int x);
node *deleteBegin(node *head);
node *deleteEnd(node *head);
node *deleteKthNode(node *head, int pos);
int Count(node *head);

int main(){
	int n;
	cin >> n;
	
	node *head = NULL;
	node *tail = NULL;
	
	for(int i = 0; i < n; i++){
		node *temp = (node *) malloc(sizeof(node));
		int data;
		cin >> data;
		temp->data = data;
		if(i == 0){
			temp->next = temp;
			head = temp;
			tail = temp;
		}
		else{
			tail->next = temp;
			temp->next = head;
			tail = temp;
		}
	}

	int x;
	cout << "Enter x" << endl;
	cin >> x;
	head = insertBegin(head, x);
	cout << "Insert at begin" << endl;
	traversal(head);
	cout << endl;

	head = insertEnd(head, x);
	cout << "Insert at end" << endl;
	traversal(head);
	cout << endl;

	head = deleteBegin(head);
	cout << "Delete at begin" << endl;
	traversal(head);
	cout << endl;

	head = deleteEnd(head);
	cout << "Delete at end" << endl;
	traversal(head);
	cout << endl;

	int pos;
	cout << "Enter position" << endl;
	cin >> pos;
	head = deleteKthNode(head, pos);
	cout << "After deleting kth element" << endl;
	traversal(head);
	cout << endl;
	
	//int count = Count(head);
	//cout << count << endl;
	return 0;
}
void traversal(node *head){
	if(head == NULL){
		return;
	}
	if(head->next == head){
		cout << (head->data);
		return;
	}
	node *cur = head;
	do{
		cout << (cur->data) << " ";
		cur = cur->next;
	}while(cur != head);
}
node *insertBegin(node *head, int x){
	node *temp = (node *) malloc(sizeof(node));
	temp->data = x;
	if(head == NULL){
		temp->next = temp;
		return temp;		
	}
	if(head->next == head){
		head->next = temp;
		temp->next = head;
		return temp;
	}
	node *cur = head;
	while(cur->next != head){
		cur = cur->next;
	}
	cur->next = temp;
	temp->next = head;
	return temp;
}
node *insertEnd(node *head, int x){
	node *temp = (node *) malloc(sizeof(node));
	temp->data = x;
	if(head == NULL){
		temp->next = temp;
		return temp;
	}
	if(head->next == head){
		temp->next = head;
		head->next = temp;
		return head;
	}
	node *cur = head;
	while(cur->next != head){
		cur = cur->next;
	}
	cur->next = temp;
	temp->next = head;
	return head;
}
node *deleteBegin(node *head){
	if(head == NULL || head->next == head){
		return NULL;
	}
	node *cur = head;
	node *newhead = head->next;
	while(cur->next != head){
		cur = cur->next;
	}
	cur->next = newhead;
	free(head);
	return newhead;
}
node *deleteEnd(node *head){
	if(head == NULL || head->next == head){
		return NULL;
	}
	node *pre = head;
	node *cur = head;
	while(cur->next != head){
		pre = cur;
		cur = cur->next;
	}
	free(cur);
	pre->next = head;
	return head;
}
node *deleteKthNode(node *head, int pos){
	if(pos <= 0){
		return head;
	}
	if(head == NULL){
		return NULL;
	}
	if(pos == 1){
		return deleteBegin(head);
	}
	node *cur = head;
	node *pre = head;
	int count = 0;
	for(int i = 1; i < pos && cur->next != head; i++){
		pre = cur;
		cur = cur->next;
		count++;
	}
	if(count != pos - 1 && cur->next == head){
		return head;
	}
	if(count == pos - 1 && cur->next == head){
		return deleteEnd(head);
	}	
	pre->next = pre->next->next;
	free(cur);
	return head;
}
int Count(node *head){
	int count = 0;
	node *cur = head;
	while(cur->next != head){
		cur = cur->next;
		count++;
	}
	return count;
}