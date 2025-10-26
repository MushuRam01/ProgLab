#include <stdio.h>
#include <stdlib.h>


int read_file_ascii(const char *filename) {

    int ch;
    

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    
    while((ch = fgetc(file)) != EOF){
        printf("%d ", ch);  // Added space for readability... each output will be an ascii
    }

    printf("\n");

    fclose(file);
    return 0;

}


int read_file_char(const char *filename) {

    int ch;
    

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    
    while((ch = fgetc(file)) != EOF){
        printf("%c", ch); //no space as verbatim each letter is thrown out
    }

    printf("\n");

    fclose(file);
    return 0;

}

int* freqarr(const char *filename, int freq[26]){
    // frequency array for lowercase letters only
    int ch;

    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("error opening\n");
        return;
    }

    while((ch = fgetc(file)) != EOF){
        if(ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
        }
    }

    fclose(file);
    return freq;
}


void printarray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void swaparray(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}



int* sortarray(int arr[], int n){
    for(int i=0; i< n-1; i++){
        for (int j=0; j< n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swaparray(arr , j , j+1);
            }
        }
    }

}


struct Node {
    char letter;
    int frequency;
    struct Node* left;
    struct Node* right;
}; 

struct Node* createNodes(int freq[26], int* nodeCount){
    struct Node* nodes = malloc(26*(sizeof(struct Node)));
    *nodeCount = 0;

    for(int i = 0; i < 26; i++){
        if(freq[i]>0){
            nodes[*nodeCount].letter = 'a' + i;
            nodes[*nodeCount].frequency = freq[i];
            nodes[*nodeCount].left = NULL;
            nodes[*nodeCount].right = NULL;
            (*nodeCount)++;
        }
    }

    return nodes;
}




int main(){
    int freq[26] = {0};
    int nodeCount;  // Variable to store how many nodes were created
    
    // Get frequency data
    freqarr("input.txt", freq);
    printarray(freq, 26);
    
    // Create nodes from frequency array
    struct Node* nodes = createNodes(freq, &nodeCount);
    
    // Print the created nodes to see if it worked
    printf("Created %d nodes:\n", nodeCount);
    for(int i = 0; i < nodeCount; i++) {
        printf("Letter: %c, Frequency: %d\n", nodes[i].letter, nodes[i].frequency);
    }
    
    // Don't forget to free the memory when done
    free(nodes);
    
    return 0;
}