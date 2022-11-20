#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
void display(struct Node * ptr);
struct Node * insertAtFirst(struct Node * ptr1, int data);
struct Node * insertAtEnd(struct Node * ptr2, int data);
struct Node * insertAtIndex(struct Node * ptr3, int data, int index);

int main(){
    printf("Enter the size of the linked list\n");
    int n;
    scanf("%d", &n);
    struct Node * head = (struct Node *) malloc(sizeof(struct Node));
    struct Node * tail = head;
    printf("Enter the numbers seperated by a space\n");
    for(int i=0; i <n;i++){
        int data;
        scanf("%d", &data);
        if(i==0){
            head->data = data;
        }
        else{
            struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
            ptr->data = data;
            tail->next = ptr;
            tail = ptr;
        }
    }
    tail->next = NULL;
    struct Node * pointer1 = head;
    printf("\nBefore Insertion\n");
    display(head);

    int newElement;
    printf("\nEnter a new element for insertion\n");
    scanf("%d",&newElement);
    head = insertAtFirst(head, newElement);
    printf("\nAfter inserting at the first\n");
    struct Node * pointer2 = head;
    display(pointer2);

    int newElement1;
    printf("\nEnter a new element for insertion at the end\n");
    scanf("%d",&newElement1);
    head = insertAtEnd(head, newElement1);
    struct Node * pointer3 = head;
    printf("\nAfter inserting at the end\n");
    display(pointer3);

    int newElement2;
    printf("\nEnter a new element for insertion at an index\n");
    scanf("%d", &newElement2);
    int index;
    printf("Enter the index for insertion\n");
    scanf("%d", &index);
    head = insertAtIndex(head, newElement2, index);
    printf("After insertion at a particular index\n");
    struct Node * pointer4 = head;
    display(pointer4);
    
    return 0;
};
void display(struct Node * ptr){
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
};
struct Node * insertAtFirst(struct Node * ptr1, int data){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = ptr1;
    return newNode;
};
struct Node * insertAtEnd(struct Node * ptr2, int data){
    struct Node * newNode1 = (struct Node *) malloc(sizeof(struct Node));
    newNode1->data = data;
    struct Node * p = ptr2;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = newNode1;
    newNode1->next = NULL;
    return ptr2;
}
struct Node * insertAtIndex(struct Node * ptr3, int data, int index){
    int count = 0;
    struct Node * p = ptr3;
    while(p->next != NULL){
        count += 1;
        p = p->next;
    }
    if(index > count){
        return ptr3;
    }
    else{
        struct Node * newNode2 = (struct Node *) malloc(sizeof(struct Node));
        newNode2->data = data;
        struct Node * before = ptr3;
        for(int i=0;i<index-1;i++){
            before = before->next;
        }
        struct Node * after = before->next;
        newNode2->next = after;
        before->next = newNode2;
    }
    return ptr3;
}