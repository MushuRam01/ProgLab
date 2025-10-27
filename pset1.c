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


int* siftup(int arr[], int i, int n){

    if(i==0){
        return arr;
    }

    if(arr[(i-1)/2] > arr[i]){ //floors the value automatically 
        swap(&arr[(i-1)/2], &arr[i]);
        siftup(arr, (i-1)/2, n);
    }
    return arr;

}

int* siftdown(int arr[], int i, int n){

    if(i==0){
        return arr;
    }

    if(arr[(2*i)+1] < arr[i]){ //floors the value automatically 
        swap(&arr[(2*i)+1], &arr[i]);
        siftup(arr, (2*i)+1, n);
    }

    if(arr[(2*i)+2] < arr[i]){ //floors the value automatically 
        swap(&arr[(2*i)+2], &arr[i]);
        siftup(arr, (2*i)+2, n);
    }
    return arr;

}
  
int* siftup_iterative(int arr[], int n){

    for(int i = n/2; i==0; i--){
        if(arr[(i-1)/2] > arr[i]){ //floors the value automatically 
        swap(&arr[(i-1)/2], &arr[i]);
        siftup(arr, (i-1)/2, n);
        }

    }

    
    return arr;

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



// Helper function to print array
void printArray(int arr[], int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1) printf(", ");
    }
    printf("]\n");
}

// Helper function to create test array without user input
void createTestArray(int arr[], int values[], int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = values[i];
    }
}

int main() {
    int choice;
    
    printf("=== PSET1 FUNCTION TESTING MENU ===\n");
    printf("1. Test Problem 1 Functions (printnto0, print1ton)\n");
    printf("2. Test trackminmax()\n");
    printf("3. Test findsecondlargest()\n");
    printf("4. Test findmedian()\n");
    printf("5. Test findkthlargest()\n");
    printf("6. Test Heap Functions (siftup, siftdown)\n");
    printf("7. Test Sorting Functions\n");
    printf("8. Run All Tests (Demo Mode)\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: {
            printf("\n=== TESTING PROBLEM 1 FUNCTIONS ===\n");
            int n;
            printf("Enter a positive integer: ");
            scanf("%d", &n);
            
            printf("printnto0(%d): ", n);
            printnto0(n);
            printf("\n");
            
            printf("print1ton(%d): ", n);
            print1ton(n);
            printf("\n");
            break;
        }
        
        case 2: {
            printf("\n=== TESTING TRACKMINMAX ===\n");
            trackminmax();
            break;
        }
        
        case 3: {
            printf("\n=== TESTING FINDSECONDLARGEST ===\n");
            printf("Enter number of elements for second largest: ");
            int count;
            scanf("%d", &count);
            if(count >= 2) {
                int second = findsecondlargest(count);
                printf("Second largest: %d\n", second);
            } else {
                printf("Need at least 2 elements to find second largest.\n");
            }
            break;
        }
        
        case 4: {
            printf("\n=== TESTING FINDMEDIAN ===\n");
            printf("Enter number of elements for median: ");
            int count;
            scanf("%d", &count);
            if(count >= 1) {
                int median = findmedian(count);
                printf("Median: %d\n", median);
            } else {
                printf("Need at least 1 element to find median.\n");
            }
            break;
        }
        
        case 5: {
            printf("\n=== TESTING FINDKTHLARGEST ===\n");
            printf("Enter number of elements for kth largest: ");
            int count;
            scanf("%d", &count);
            if(count >= 1) {
                int kth = findkthlargest(count);
                if(kth != -1) {
                    printf("Kth largest: %d\n", kth);
                }
            } else {
                printf("Need at least 1 element to find kth largest.\n");
            }
            break;
        }
        
        case 6: {
            printf("\n=== TESTING HEAP FUNCTIONS ===\n");
            int testData[] = {4, 10, 3, 5, 1};
            int n = 5;
            int arr[5];
            
            // Test siftup
            createTestArray(arr, testData, n);
            printf("Original array: ");
            printArray(arr, n);
            
            printf("Testing siftup at index 4 (value %d):\n", arr[4]);
            siftup(arr, 4, n);
            printf("After siftup: ");
            printArray(arr, n);
            
            // Reset array for siftdown test
            createTestArray(arr, testData, n);
            printf("\nTesting siftdown at index 1 (value %d):\n", arr[1]);
            siftdown(arr, 1, n);
            printf("After siftdown: ");
            printArray(arr, n);
            break;
        }
        
        case 7: {
            printf("\n=== TESTING SORTING FUNCTIONS ===\n");
            int testData[] = {64, 34, 25, 12, 22, 11, 90};
            int n = 7;
            int arr[7];
            
            createTestArray(arr, testData, n);
            printf("Original array: ");
            printArray(arr, n);
            
            bubbleSort(arr, n);
            printf("After bubble sort: ");
            printArray(arr, n);
            break;
        }
        
        case 8: {
            printf("\n=== DEMO MODE - TESTING ALL FUNCTIONS ===\n");
            
            // Test Problem 1 functions
            printf("\n1. Testing printnto0(5) and print1ton(5):\n");
            printf("printnto0(5): ");
            printnto0(5);
            printf("\nprint1ton(5): ");
            print1ton(5);
            printf("\n");
            
            // Test sorting with predefined data
            printf("\n2. Testing bubble sort:\n");
            int sortData[] = {64, 34, 25, 12, 22};
            int sortArr[5];
            createTestArray(sortArr, sortData, 5);
            printf("Before sort: ");
            printArray(sortArr, 5);
            bubbleSort(sortArr, 5);
            printf("After sort: ");
            printArray(sortArr, 5);
            
            // Test heap functions
            printf("\n3. Testing heap operations:\n");
            int heapData[] = {4, 10, 3, 5, 1};
            int heapArr[5];
            createTestArray(heapArr, heapData, 5);
            printf("Original: ");
            printArray(heapArr, 5);
            siftup(heapArr, 4, 5);
            printf("After siftup(4): ");
            printArray(heapArr, 5);
            
            printf("\nFor interactive tests (min/max, median, etc.), use options 2-5.\n");
            break;
        }
        
        case 0:
            printf("Exiting...\n");
            break;
            
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
    
    return 0;
}