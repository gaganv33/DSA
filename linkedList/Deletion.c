#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
void display(struct Node * ptr1);
struct Node * deleteFirstNode(struct Node * ptr2);
struct Node * deleteLastNode(struct Node * ptr3);
struct Node * deleteIndexNode(struct Node * ptr4, int index);

int main(){
    int n;
    printf("Enter the length of the linked list\n");
    scanf("%d", &n);

    struct Node * head = (struct Node *) malloc(sizeof(struct Node));
    struct Node * tail = head;
    printf("Enter the numbers seperated by a space\n");
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
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

    printf("\nBefore Deletion\n");
    struct Node * pointer1 = head;
    display(pointer1);

    printf("\nAfter deleting the first node\n");
    head = deleteFirstNode(head);
    struct Node * pointer2= head;
    display(pointer2);

    printf("\nAfter deleting the last node\n");
    head = deleteLastNode(head);
    struct Node * pointer3 = head;
    display(head);

    printf("\nEnter the index for deletion\n");
    int index;
    scanf("%d", &index);
    head = deleteIndexNode(head, index);
    printf("\nAfter deleting at a particular index\n");
    display(head);

    return 0;
}
void display(struct Node * ptr1){
    while(ptr1 != NULL){
        printf("%d ", ptr1->data);
        ptr1 = ptr1->next;
    }
}
struct Node * deleteFirstNode(struct Node * ptr2){
    struct Node * test1 = ptr2->next;
    free(ptr2);
    return test1;
}
struct Node * deleteLastNode(struct Node * ptr3){
    struct Node * test2 = ptr3;
    while(test2->next->next != NULL){
        test2 = test2->next;
    }
    free(test2->next);
    test2->next = NULL;
    return ptr3;
}
struct Node * deleteIndexNode(struct Node * ptr4, int index){
    int count = 0;
    struct Node * p = ptr4;
    while(p->next != NULL){
        count += 1;
        p = p->next;
    }
    printf("\nNumber of elements before deletion: %d\n", count+1);
    if(index > count || index < 0){
        return ptr4;
    }
    else if(index <= count && index > 0){
        struct Node * test3 = ptr4;
        for(int i = 0;i<index-1;i++){
            test3 = test3->next;
        }
        struct Node * after = test3->next;
        test3->next = after->next;
        free(after);
        return ptr4;
    }
    else if(index <= count && index == 0){
        struct Node * test4 = ptr4;
        test4 = ptr4->next;
        return test4;
    }
}