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
//2.1, 2.2 find maximum and minimum

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



// 2.3 find second largest   I will store values in array then  use sorting to find second largest element
void makearray(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = readvalue();
    }
}

// A function to swap two elements
void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort that returns a pointer to the sorted array
int* bubbleSort(int arr[], int n) {
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (swapped == 0)
            break;
    }
    return arr;
}

int findsecondlargest(int n){
    int arr[n];
    makearray(arr, n);
    bubbleSort(arr, n);
    return arr[n-2]; // second largest element (second from end after sorting)
}

// 2.4 -- find the median of a given sequence of integers from user 
int findmedian(int n){
    int arr[n];
    makearray(arr,n);
    bubbleSort(arr,n);
    if(n%2==0){
        return (arr[n/2] + arr[(n/2)-1])/2 ;
    }
    if(n%2!=0){
        return arr[(n-1)/2];
    }
}


// 2.5 -- find the kth largest integer in a given sequence of integers from user k is also given by user
int findkthlargest(int n){
    int arr[n];
    int k;
    makearray(arr, n);
    bubbleSort(arr,n);
    printf("enter value of k to find kth lrgest integer: ");
    scanf("%d", &k);
    if(k==0){
        printf("K cannot be 0\n");
        return -1; // Return error value
    }
    if(k>n){
        printf("k cannot be larger than number of elements\n");
        return -1; // Return error value
    }
    if(k>0 && k<=n){
        return arr[n-k];
    }
    else{
        printf("Invalid k value\n");
        return -1; // Return error value
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
    trackminmax();
    
    printf("Enter number of elements for second largest: ");
    int count;
    scanf("%d", &count);
    if(count >= 2) {
        int second = findsecondlargest(count);
        printf("Second largest: %d\n", second);
    } else {
        printf("Need at least 2 elements to find second largest.\n");
    }
    
    return 0;
}