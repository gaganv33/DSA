#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int f;
    int n;
    printf("Enter the number of frames ");
    scanf("%d", &f);
    printf("Enter the number of pages ");
    scanf("%d", &n);

    int frames[f];
    for(int i = 0; i < f; i++){
        frames[i] = -1;
    }
    int request[n];
    int max_value = -1;
    for(int i = 0; i < n; i++){
        scanf("%d", &request[i]);
        if(request[i] > max_value){
            max_value = request[i];
        }
    }

    int check[max_value + 1];
    

    int i = 0;
    int j = 0;

    while(i < f && j < n){
        int found = 0;
        for(int k = 0; k < f; k++){
            if(frames[k] == request[j]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            frames[i] = request[j];
            i++;
        }
        for(int k = 0; k < f; k++){
            printf("%d ", frames[k]);
        }
        printf("\n");
        j++;
    }

    while(j < n){
        int found = 0;
        for(int k = 0; k < f; k++){
            if(frames[k] == request[j]){
                found = 1;
                break;
            }
        }
        
        if(found == 0){
            for(int k = 0; k < max_value + 1; k++){
                check[k] = -100;
            }
            int flag = 0;
            for(int k = 0; k < f; k++){
                int index = -1;
                for(int b = j + 1; b < n; b++){
                    if(request[b] == frames[k]){
                        index = b;
                        break;
                    }
                }
                if(index == -1){
                    flag = 1;
                    frames[k] = request[j];
                    break;
                }
                else{
                    check[frames[k]] = index;
                }
            }
            if(flag == 0){
                int answer = -1;
                int min_value = -100000;
                for(int k = 0; k < max_value + 1; k++){
                    if(check[k] != -100){
                        if(check[k] > min_value){
                            min_value = check[k];
                            answer = k;
                        }
                    }
                }
                for(int k = 0; k < f; k++){
                    if(frames[k] == answer){
                        frames[k] = request[j];
                        break;
                    }
                }
            }
        }

        for(int k = 0; k < f; k++){
            printf("%d ", frames[k]);
        }
        printf("\n");
        j++;
    }

    return 0;
}