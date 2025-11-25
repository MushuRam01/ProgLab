//Aarush Ram Anandh

#include <stdio.h>
#include <stdlib.h>




int main(){
    srand(42);

    int freq[4]={0,0,0,0};
    int ch;

    FILE *fptr;
    fptr = fopen("100.txt","r");

    while((ch=fgetc(fptr)) != EOF){
        if(ch == 'a'){
            freq[0]++ ;
        }
        if(ch == 'b'){
            freq[1]++ ;
        }
        if(ch == 'c'){
            freq[2]++ ;
        }
        if(ch == 'd'){
            freq[3]++ ;
        }
    }

    for(int i =0; i<4;i++){
        printf("%d",freq[i]);
        printf(" ");
    }



    fclose(fptr);
    return 0;
}