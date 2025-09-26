#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char buf ;
int bufsize=0;

// Function prototypes
void ShuffleArray(int *A, int n);
void swap(int *A, int i, int j);
void printArray(int *A, int n);


void output (FILE*X, int b){
    if(bufsize==0){
        buf = 0;

    }

    buf = ( buf << 1) | b ; //left-shift by 1  then a bitwise or... it is diffrent from using || which is the usual OR we use 
    bufsize++;

    if(bufsize==8){
        fputc(X,buf);
        bufsize = 0;
    }
    buf = (buf << 1)|b ;
    bufsize++;;
}

int main (void){
    int test = 5;
    test = test << 1 ;
    printf("%d\n", test);
    return test;
    
}