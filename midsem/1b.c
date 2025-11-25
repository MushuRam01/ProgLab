//Aarush Ram Anandh

#include <stdio.h>
#include <stdlib.h>


int randomN(){
    srand(42);
    int num=rand()%4 ;
    return num;
}
//code works
int main(){
    srand(42);
    char arr[4] = {'a','b','c','d'};



    FILE *fptr;
    fptr = fopen("lett.txt","w");

    for(int i =0; i<1000; i++){
        
        int num=rand()%4 ;
        char lett = arr[num];
        fputc(lett, fptr);

    }

    fclose(fptr);
    return 0;
}