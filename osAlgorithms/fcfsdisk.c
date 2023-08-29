#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int r;
    printf("Enter the range of the disk ");
    scanf("%d", &r);
    int n;
    printf("Enter the size of the request queue ");
    scanf("%d", &n);

    int request[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &request[i]);
    }
    int head;
    printf("Enter the head position: ");
    scanf("%d", &head);
    int seekTime = 0;
    for(int i = 0; i < n; i++){
        printf("Disk head moves from %d to %d\n", head, request[i]);
        seekTime += abs(head - request[i]);
        head = request[i];
    }
    printf("Total seek Time is: %d", seekTime);
    return 0;
}