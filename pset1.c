#include <stdio.h>
#include <stdlib.h>
//Problem 1
int readvalue(void) {
    int value;
    printf("Enter an integer: ");
    scanf("%d", &value);
    return value;

}

void printnto0(int n){ //-----Complexity O(n) -----
    printf("%d ", n);

    if(n > 0){
        printnto0( n-1);
    }
   
}

void print1ton(int n){ //-----Complexity O(n) -----
    for(int i=0; i<=n; i++){
        printf("%d ", i);
    }
}
//Problem 2

void trackminmax(int n){ //-----Complexity O(n) -----

    int initmin;
    int initmax;
    int k;
    int val;
    printf("Enter number of values: ");
    scanf("%d",&k);
    
    if(k!=0 && k>0){
        for(int i = 1; i <= k; i++){
        val = readvalue();
        if(val < initmin){
            initmin = val;
        }
        if(val > initmax){
            initmax = val;
        }
     }
        printf("Min: %d, Max: %d\n", initmin, initmax);
    }
    else{
        printf("No values to read.\n");
        return;

    }

    
}






int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printnto0(n);
    printf("\n");
    print1ton(n);
    printf("\n");
    trackminmax(n);
    return 0;
   
}