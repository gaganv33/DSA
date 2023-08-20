#include<stdio.h>

int main(){
    int f;
    int p;
    printf("Enter the no. of frames: ");
    scanf("%d", &f);
    printf("Enter the no. of pages: ");
    scanf("%d", &p);

    int pages[p];
    for(int i = 0; i < p; i++){
        scanf("%d", &pages[i]);
    }
    int frames[f];
    for(int i = 0; i < f; i++){
        frames[i] = -1;
    }
    int index = 0;
    int old = 0;
    for(int i = 0; i < p; i++){
        if(index < f){
            frames[index] = pages[i];
            index++;
        }
        else{
            if(old == f){
                old = 0;
            }
            frames[old] = pages[i];
            old++;
        }
        for(int j = 0; j < f; j++){
            printf("%d ", frames[j]);
        }
        printf("\n");
    }
    return 0;
}


