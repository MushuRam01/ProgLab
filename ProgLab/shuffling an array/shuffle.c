#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Function prototypes
void ShuffleArray(int *A, int n);
void swap(int *A, int i, int j);
void printArray(int *A, int n);

int main(void) {
    // Initialize the substitution key array S
    int S[26];
    for (int i = 0; i < 26; i++) {
        S[i] = i;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the array to create a random substitution key
    ShuffleArray(S, 26);

    // Print the shuffled array to verify the result
    printf("Shuffled Substitution Key:\n");
    printArray(S, 26);

    return 0;
}

// Fisher-Yates shuffle implementation
void ShuffleArray(int *A, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(A, i, j);
    }
}

// Helper function to swap two elements in an array
void swap(int *A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Helper function to print the contents of an array
void printArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", A[i] + 'A'); // Print as a character
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]); // Print as a number
    }
    printf("\n");
}