#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct Process{
    int pid;
    int memory;
    int blockSize;
};

int main(){
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for(int i = 0; i < n; i++){
        p[i].pid = i + 1;
        p[i].memory = -1;
        scanf("%d", &p[i].blockSize);
    }
    int m;
    printf("Enter the number of blocks ");
    scanf("%d", &m);
    int block[m];
    for(int i = 0; i < m; i++){
        scanf("%d", &block[i]);
    }
    for(int i = 0; i < n; i++){
        int index = -1;
        for(int j = 0; j < m; j++){
            if(block[j] >= p[i].blockSize){
                index = j;
                break;
            }
        }
        if(index != -1){
            block[index] -= p[i].blockSize;
            p[i].memory = index;
        }
    }
    for(int i = 0; i < n; i++){
        printf("Process id: %d, memory block allocated: %d\n", p[i].pid, p[i].memory + 1);
    }
    return 0;
}