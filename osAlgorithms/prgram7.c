#include<stdio.h>

int main(){
    int n;
    int r;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ", &r);
    scanf("%d", &r);

    int max[n][r];
    int need[n][r];
    int alloc[n][r];
    int available[r];
    int ans[n];
    for(int i = 0; i  <n; i++){
        ans[i] = -100;
    }

    printf("Enter the allocated resources\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < r; j++){
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the maximum resources required\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < r; j++){
            scanf("%d", &max[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < r; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("Enter availabel resources\n");
    for(int i = 0; i < r; i++){
        scanf("%d", &available[i]);
    }

    int l = 0;
    for(int i = 0; i < n; i++){
        int index = -1;
        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int k = 0; k < r; k++){
                sum += need[j][k];
            }
            if(sum == 0){
                continue;
            }
            int found = 1;
            for(int k = 0; k < r; k++){
                if(need[j][k] > available[k]){
                    found = 0;
                    break;
                }
            }
            if(found == 1){
                index = j;
                break;
            }
        }
        if(index != -1){
            ans[l] = index;
            l++;
            for(int k = 0; k < r; k++){
                need[index][k] = 0;
                available[k] += alloc[index][k];
            }
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(ans[i] == -100){
            count = i;
        }
    }
    if(count == 0){
        printf("No deadlock\n");
        for(int i = 0; i < n; i++){
            printf("%d ", ans[i]);
        }
    }
    else{
        printf("Deadlock");
    }
    return 0;
}