#include<stdio.h>

int main(){
    int memorySize;
    int pageSize;
    printf("Enter the memory size: ");
    scanf("%d", &memorySize);
    printf("Enter the page size: ");
    scanf("%d", &pageSize);
    
    int nop = memorySize / pageSize;
    printf("The total number of available pages in the secondary memory: %d\n", nop);
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int page[nop];
    for(int i = 0; i < nop; i++){
        page[i] = -1;
    }
    int count = nop;
    for(int i = 0; i < n; i++){
        printf("Enter the no. of pages required for p[%d]: ", i + 1);
        int m;
        scanf("%d", &m);
        if(m > count){
            printf("Memory is full\n");
        }
        else{
            count -= m;
            for(int j = 0; j < m; j++){
                int index;
                scanf("%d", &index);
                if(index >= nop){
                    printf("Invalid index\n");
                }
                else{
                    if(page[index] == -1){
                        page[index] = i + 1;
                    }
                    else{
                        printf("Invalid index\n");
                    }
                }
            }
        }
    }
    int processNo;
    int pageNo;
    int offset;
    int ans;
    printf("Enter the process number, page number and offset\n");
    scanf("%d%d%d", &processNo, &pageNo, &offset);
    for(int i = 0; i < nop; i++){
        if(page[i] == processNo){
            if(pageNo == 0){
                ans = i;
                break;
            }
            pageNo--;
        }
    }
    printf("The physical address is: %d", (ans * pageSize) + offset);
    return 0;
}