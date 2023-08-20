#include<stdio.h>

struct process{
    int pid;
    int memory;
    int block;
};

int main(){
    int n;
    int m;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of block: ");
    scanf("%d", &m);

    struct process p[n];
    int blockSize[m];

    printf("Enter the size of each process\n");
    for(int i = 0; i < n; i++){
        printf("Enter the size of the process p%d: ", i + 1);
        scanf("%d", &p[i].memory);
        p[i].pid = i + 1;
        p[i].block = -1;
    }
    printf("Enter the size of each block\n");
    for(int i = 0; i < m; i++){
        scanf("%d", &blockSize[i]);
    }

    for(int i = 0; i < n; i++){
        int index = -1;
        int minMemory = 100000;
        for(int j = 0; j < m; j++){
            if(blockSize[j] >= p[i].memory && blockSize[j] < minMemory){
                index = j;
                minMemory = blockSize[j];
            }
        }
        if(index != -1){
            p[i].block = index + 1;
            blockSize[index] = blockSize[index] - p[i].memory;
        }
    }
    printf("Process No\tProcess Size\tBlock No\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\n", p[i].pid, p[i].memory, p[i].block);
    }
    for(int i = 0; i < m; i++){
        printf("%d ", blockSize[i]);
    }
    return 0;
}

