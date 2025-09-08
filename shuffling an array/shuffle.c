#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // ise the isalpha(); function
// read fischer-yates wiki for permutations
 

int main (void) {
    int S[26];
    int test[5];
    int i;
    for (i=0; i<26, i=i+1;){
        S[i]=i ;
    }
    for( i=0; i<26; i=i+1){
        printf("%d\n", S[i]);
        
    }
    for (i=0; i<5, i=i+1;){
        S[i]=i ;
    }


    //write code here to encripyt a text file after refernecing to the shuffled/rotated lookup table
    






    return 0;
}



void ShuffleArray(int * A,int n){
    srand(12345); // comsider i as the cursor to the array
    // n is the size of the array thereore maximum index is n-1
    int i ;
    for( i=n-1;i>0;i=i-1){
        j= rand()%i;
        swap(A,i,j); //rewrite this properly 
    }
}

void RotateArr(int* A, int n, int rot){
    int* buff = (int*) malloc(rot * sizeof(int));
    memcpy(buff, A , rot * sizeof(int));
    for(i=rot;i<n;i=i+1){
        //shift places
    }
    memcpy();//copy from buffer to a the last remaining elements 
}

