#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};
typedef struct Node node;

void print(node *head);
void printRecursive(node *head);
int Search(node *head, int key);
int SearchRecursive(node *head, int key, bool found, int count);
node *insertBegin(node *head, int x);
node *insertEnd(node *head, int x);
node *deleteBegin(node *head);
node *deleteEnd(node *head);
node *insertPos(node *head, int x, int index);
node *sortedInsert(node *head, int x);
void middleNode(node *head);
void NthNode(node *head, int n);
node *reverse(node *head);
node *removeDuplicates(node *head);
node *recRev(node *cur, node *prev);

node *head = (node*) malloc(sizeof(node));
node *tail = head;

int main(){
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		if(i == 0){
			cin >> head->data;
			head->next = NULL;
		}
		else{
			node *temp = (node*) malloc(sizeof(node));
			cin >> temp->data;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
		}
	}
	cout << "Iterative" << endl;
	print(head);
	cout << endl;
	node *cur = head;
	cout << "Recursive" << endl;
	printRecursive(cur);
	cout << endl;
	int key;
	cin >> key;
	cout << "Search Iterative" << endl;
	cout << Search(head, key) << endl;
	cout << "Search Recursive" << endl;
	cur = head;
	cout << SearchRecursive(cur, key, false, 0) << endl;
	
	int x;
	cin >> x;
	head = insertBegin(head, x);
	print(head);
	cout << endl;
	head = insertEnd(head, x);	
	print(head);
	cout << endl;
	head = deleteBegin(head);
	print(head);
	cout << endl;
	head = deleteEnd(head);
	printRecursive(head);
	cout << endl;
	cout << "Insert at position" << endl;
	int index;
	cin >> index;
	head = insertPos(head, x, index);
	print(head);
	cout << endl;
	cout << "Sorted Insert" << endl;
	int y;
	cin >> y;
	head = sortedInsert(head, y);
	print(head);
	cout << endl;
	cout << "Value of the middle node" << endl;
	middleNode(head);		
	cout << endl;
	cout << "Value of the nth node" << endl;
	cin >> n;
	NthNode(head, n);
	cout << endl;
	cout << "Reverse" << endl;
	head = recRev(head, NULL);
	print(head);
	cout << endl;	
	cout << "Remove duplicates" << endl;
	head = removeDuplicates(head);
	print(head);
	cout << endl;
	//cout << "Test" << endl;
	//head = deleteBegin(head);
	//print(head);
	//cout << endl;
	//head = deleteBegin(head);
	//print(head);
	//cout << endl;
	return 0;	
}
void print(node *head){
	node *cur = head;
	while(cur != NULL){
		cout << cur->data << " ";
		cur = cur->next;
	}	
}
void printRecursive(node *head){
	if(head == NULL){
		return;
	}
	cout << head->data << " ";
	printRecursive(head->next);
}                
int Search(node *head, int key){
	node *cur = head;
	int count = 1;
	while(cur != NULL){
		if(cur->data == key){
			return count; 	
		}
		count++;
		cur = cur->next;
	}
	return -1;
}                 
int SearchRecursive(node *head, int key, bool found, int count){
	if(head == NULL){
		count = -1;
		return count;
	}
	if(!found){
		count++;
		if(head->data == key){
			return count;
			found = true;
		}
	}
	return SearchRecursive(head->next, key, found, count);
}
node *insertBegin(node *head, int x){
	node *temp = (node *) malloc(sizeof(node));
	temp->data = x;
	temp->next = head;
	return temp;
}
node *insertEnd(node *head, int x){
	node *temp = (node *) malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;
	
	if(head == NULL){
		return temp;
	}
	
	node *cur = head;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = temp;
	return head;
}
node *deleteBegin(node *head){
	if(head == NULL || head->next == NULL){
		free(head);
		return NULL;
	}
	node *cur = head;
	head = cur->next;
	cur->next = NULL;
	free(cur);
	return head;
}
node *deleteEnd(node *head){
	if(head == NULL || head->next == NULL){
		free(head);
		return NULL;
	}
	node *cur = head;
	node *pre = NULL;
	
	if(head->next == NULL || head == NULL){
		return NULL; 	
	}
	
	while(cur->next != NULL){
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	free(cur);
	return head;
}
node *insertPos(node *head, int x, int index){
	if(index == 0){
		head = insertBegin(head, x);
		return head;
	}
	node *temp = (node *) malloc(sizeof(node));
	temp->data = x;
	if(index == 1){
		temp->next = head->next;
		head->next = temp;
	}
	else{
		node *cur = head;
		int pos = 1;
		while(pos < index){
			if(cur == NULL){
				return head;
			}
			cur = cur->next;
			pos++;
		}
		if(cur == NULL){
			return head;
		}
		temp->next = cur->next;
		cur->next = temp;
	}
	return head;
}
node *sortedInsert(node *head, int x){
	node *temp = (node *) malloc(sizeof(node));
	temp->data = x;
	if(head == NULL){
		temp->next = NULL;
		return temp;		
	}
	if(x < head->data){
		temp->next = head;
		head = temp;
		return head;
	}
	node *pre = NULL;
	node *cur = head;
	while(cur != NULL && cur->data < x){
		pre = cur;
		cur = cur->next;
	}
	temp->next = pre->next;
	pre->next = temp;
	return head;
}
void middleNode(node *head){
	if(head == NULL){
		return; 	
	}
	node *slow = head;
	node *fast = head;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << (slow->data) << endl;
	return;
}
void NthNode(node *head, int n){
	if(head == NULL){
		return;
	}
	node *first = head;
	node *second = head;
	
	for(int i = 0; i < n; i++){
		if(first == NULL){
			return; 	
		}
		first = first->next;
	}	
	
	while(first != NULL){
		second = second->next;
		first = first->next;
	}
	cout << (second->data) << endl;
	return;
}
node *reverse(node *head){
	if(head == NULL){
		return NULL;
	}
	node *curr = head;
	node *prev = NULL;
	while(curr != NULL){
		node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
node *removeDuplicates(node *head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	node *cur = head;
	while(cur != NULL){
		if(cur->next == NULL){
	        	break;
		}
		else{
			if(cur->data == cur->next->data){
				if(cur->next->next == NULL){
					cur->next = NULL;
					break;
				}
				else{
					node *temp = cur->next;
					cur->next = cur->next->next;
					free(temp);
				}
			}
			else{
				cur = cur->next;
			}
		}
	}
	return head;
}
node *recRev(node *cur, node *prev){
	if(cur == NULL){
		return prev;
	}
	Node *next = cur->next;
	cur->next = prev;
	return recRev(next, cur);
}