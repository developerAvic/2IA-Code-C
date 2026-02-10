#include <stdio.h>
#include <stdlib.h>
#define m 20 // sixe of hash table

int key[20]; // An array to store the initial keys you input
int n; // to store number of keys user want to enter
int *a; // a pointer used for the Hash Table
int index1; // A global helper variable used to store the calculated position (hash value) of a key. 
int count = 0;  // A tracker to keep count of how many slots in the table are currently filled



// linear probing takes the raw value from key
// calculates key's hashed value - using modulus operator
// if the index in the hash table is occupied (!= to -1)
    // perform linear probing: check the very next spot
// else insert the key in hash table with an empty spot
// increment the count variable to keep track of no. of elements

void linearprobing(int key) {
    index1 = key % m;
    while (a[index1] != -1) {
        index1 = (index1 + 1) % m;
    }
    a[index1] = key; 
    count++;
}


// if the count is 0 table is empty
// run a for loop for the size of hash table
    // if occupied print the index and its value
    // else display the index with empty.

void display() {
    int i;
    if (count == 0) {
        printf("\nHash Table is empty\n");
        return;
    }
    printf("\nHash Table contents are:\n");
    for (i = 0; i < m; i++) {
        if (a[i] != -1)
            printf("\n T[%2d] --> %d", i, a[i]);
        else
            printf("\n T[%2d] --> empty", i);
    }
    printf("\n");
}


// get the number of keys from the user
// allocate the array with size of hash table
// assign the value of each index in the array a to -1 for the size of hash table
// ask user to enter the values to be stored in the table
// for loop until the number of keys entered by user
    // if the count is equal to max size of hash table - cannot insert an element
    // pass key[i] to linear probing
// display the hash table

int main() {
    int i;
    
    printf("\nEnter the number of keys: ");
    scanf("%d", &n);
    
    a = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        a[i] = -1;
    }
    
    printf("\nEnter the key values:\n");
    for (i = 0; i < n; i++) {
        scanf("%4d", &key[i]);
    }

    for (i = 0; i < n; i++) {
        if (count == m) {
            printf("Hash table is full);
            break;
        }
        linearprobing(key[i]);
    }
    display();
    free(a);
    return 0;
}
