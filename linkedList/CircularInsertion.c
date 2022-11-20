#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
void display(struct Node * ptr1);
struct Node * insertAtFirst(struct Node * head2, struct Node * tail2, int data);
struct Node * insertAtLast(struct Node * tail3, int data);
struct Node * insertAtIndex(struct Node * head4, struct Node * tail4 ,int data, int index);

int main(){
    int n;
    printf("Enter the length of the circular linked list\n");
    scanf("%d", &n);

    struct Node * head = (struct Node *) malloc(sizeof(struct Node));
    struct Node * tail = head;
    printf("Enter the numbers seperated by a space\n");
    for(int i=0;i<n;i++){
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
    tail->next = head;

    struct Node * pointer1 = head;
    printf("\nCircular Linked list, before insertion\n");
    display(pointer1);

    int newElement1;
    printf("\nEnter a number for inserting before the first node\n");
    scanf("%d", &newElement1);
    printf("Circular linked list, after inserting at the first\n");
    head = insertAtFirst(head, tail, newElement1);
    struct Node * pointer2 = head;
    display(pointer2);

    int newElement2;
    printf("\nEnter a number for inserting after the last node\n");
    scanf("%d", &newElement2);
    printf("Circular linked list, after inserting at the last\n");
    head = insertAtLast(tail, newElement2);
    struct Node * pointer3 = head;
    display(pointer3);

    int newElement3;
    printf("\nEnter a number for inserting at a particular index\n");
    scanf("%d", &newElement3);
    int index;
    printf("Index\n");
    scanf("%d", &index);
    printf("Circular Linked List, after inserting at a particular index\n");
    head = insertAtIndex(head, tail, newElement3, index);
    struct Node * pointer4 = head;
    display(pointer4);

    return 0;
}
void display(struct Node * ptr1){
    struct Node * test1 = ptr1;
    while(test1->next != ptr1){
        printf("%d ", test1->data);
        test1 = test1->next;
    }
    printf("%d ", test1->data);
}
struct Node * insertAtFirst(struct Node * head2, struct Node * tail2, int data){
    struct Node * newNode2 = (struct Node *) malloc(sizeof(struct Node));
    newNode2->data = data;
    newNode2->next = head2;
    tail2->next = newNode2;
    return newNode2;
}
struct Node * insertAtLast(struct Node * tail3, int data){
    struct Node * newNode3 = (struct Node *) malloc(sizeof(struct Node));
    newNode3->data = data;
    newNode3->next = tail3->next;
    tail3->next = newNode3;
    return newNode3->next;
}
struct Node * insertAtIndex(struct Node * head4, struct Node * tail4 ,int data, int index){
    struct Node * q = head4;
    int count = 0;
    while(q->next != head4){
        count = count + 1;
        q = q->next;
    }
    count = count + 1;

    if(index > count || index < 0){
        return head4;
    }
    else if(index <= count && index > 0){
        struct Node * newNode4 = (struct Node *) malloc(sizeof(struct Node));
        newNode4->data = data;
        struct Node * before = head4;
        for(int i=0;i<index-1;i++){
            before = before->next;
        }
        struct Node * after = before->next;
        newNode4->next = after;
        before->next = newNode4;
        return head4;
    }
    else if(index <= count && index == 0){
        struct Node * newNode5 = (struct Node *) malloc(sizeof(struct Node));
        newNode5->data = data;
        newNode5->next = head4;
        tail4->next = newNode5;
        return newNode5;
    }
}