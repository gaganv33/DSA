#include<stdio.h>

int main(){
    int frames;
    int pages;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    int page[100];
    printf("Enter the pages\n");
    for(int i = 0; i < pages; i++){
        scanf("%d", &page[i]);
    }
    int f[10];
    for(int i = 0; i < frames; i++){
        f[i] = -1;
    }
    if(pages >= frames){
        int i = 0;
        int index = 0;
        while(index < frames && i < pages){
            int found = 0;
            for(int j = 0; j < frames; j++){
                if(f[j] == page[i]){
                    found = 1;
                    break;
                }
            }
            if(found == 0){
                f[index] = page[i];
                index++;

            }
            for(int j = 0; j < frames; j++){
                printf("%d ", f[j]);
            }
            printf("\n");
            i++;
        }
        index = 0;
        i = frames;
        while(i < pages){
            int found = 0;
            for(int j = 0; j < frames; j++){
                if(f[j] == page[i]){
                    found = 1;  
                }
            }
            if(found == 0){
                if(index == frames){
                    index = 0;
                }
                f[index] = page[i];
                index++;
            }
            for(int j = 0; j < frames; j++){
                printf("%d ", f[j]);
            }
            printf("\n");
            i++;
        }
    }
    else{
        for(int i = 0; i < pages; i++){
            f[i] = page[i];
        }
    }
    return 0;
}