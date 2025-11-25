//Aarush Ram Anandh
#include <stdio.h>
#include <stdlib.h>

int randomN(){
    srand(42);
    int num=rand()%1000000 ;
    return num;
}

int main(){
    srand(42);

    FILE *fptr;
    fptr = fopen("100.txt","w");

    for(int i =0; i<100; i++){
        
        int num=rand()%1000000 ;
        printf("%d",num);
        fputc(fptr,num); // values are not beinng saved as integers ... cant fihure houw to use fprintf
        printf(" ");
    }


    fclose(fptr);
    return 0;
}