#include<stdio.h>

struct process{
    int pid;
    int memory;
    int block;
};

int main(){
    int n;
    int m;
    printf("Enter the number of proccesses\n");
    scanf("%d", &n);
    printf("Enter the number of memeory blocks\n");
    scanf("%d", &m);
    struct process p[n];
    int blockSize[m][m];

    printf("Enter the process size\n");

    for(int i = 0; i < n; i++){
        printf("Enter the memory required for the process p%d: ", i + 1);
        p[i].pid = i + 1;
        scanf("%d", &p[i].memory);
        p[i].block = -1;
    }
    printf("Enter the memory block size\n");
    for(int i = 0; i < m; i++){
        printf("Enter the size of the memory block %d: ", i + 1);
        scanf("%d", &blockSize[i][0]);
        blockSize[i][1] = -1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(blockSize[j][0] >= p[i].memory && blockSize[j][1] == -1){
                p[i].block = j + 1;
                blockSize[j][1] = i + 1;
                break;
            }
        }
    }

    printf("Process No\tProcess Size\tBlock No\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\n", p[i].pid, p[i].memory, p[i].block);
    }
    return 0;
}