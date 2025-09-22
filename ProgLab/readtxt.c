#include <stdio.h>
#include <stdlib.h>





int main(void) {

    FILE *ptr ; //creating file porinter name ptr
    int i;
    int n = 27;
    int *A;
    int v;
    char ch;

    FILE *outptr;
    ptr = fopen("out.txt", "w"); // writing to output file

    A = (int*) malloc(n * sizeof(int)); // this is the og way of creating a[27]


    ptr = fopen("read.txt","r") ; //opening file

    if (ptr == NULL) {                        //check if file exists
        printf("file not fond\n");
        return 1;
    }

    while( (ch=fgetc(ptr)) != EOF ) {
        printf("%c", ch);
        
        v= (int)ch - 'a' ;
        if(v>=0 && v<26){
            A[v] = A[v]+1;
        }
        else{
            A[26]=A[26]+1;
        }

    }

    for( i=0; i<n; i=i+1){
        printf("%d\n", A[i]);
        fprintf(outptr, A[i]);
        fprintf(outptr, (char) A[i]);
    }



    
    
    return 0;

}