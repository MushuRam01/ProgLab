#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void trackminmax( void ){ //-----Complexity O(n) -----

    int initmin = INT_MAX; // largest possible vallue
    int initmax = INT_MIN; // smallest possible value
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


//Problem3    I will use merge sort to sort the array and then return the second largest element

void findsecondlargest( void ){ 

    


}




int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printnto0(n);
    printf("\n");
    print1ton(n);
    printf("\n");
    trackminmax();
    findsecondlargest();
    
    return 0;
   
}