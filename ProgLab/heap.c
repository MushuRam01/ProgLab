#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main( void ){
    int arr[20];
    unsigned int custom_seed = 12345;
    int random_range ;
    int lower = 50, upper = 69;

    int H[13] = {5, 19, 15, 23, 81, 18, 20, 30, 40, 90, 82, 25, 42}; // a correct heap 
    int temp = 0 ;

    for(int i = 0;i<20; i++){  // generic array with ranom values 
        random_range = (rand() % (upper - lower + 1)) + lower;
        arr[i]= random_range ;
    }

    printArray(arr,20);
    


    return 0;
}

void printArray(int *arr, int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void extract(int*H, int n){
    int t = H[0];
    n--;
    H[0]=H[n];
    siftdown(H,0,n);
    return t;
}

void siftdown(int* H, int i, int n){
    int p=i , lc=2*i +1, rc=2*i +2 ;
    int dummy;
    if (H[p]<=H[lc] && H[p]<=H[rc]){
        return H ;
    }

    if (H[p]>H[lc]){
        dummy = H[p];
        H[p]=H[lc];
        H[lc]=dummy;

        siftdown(H,)
    }

}