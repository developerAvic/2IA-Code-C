
#include <stdio.h>
#include <stdlib.h>

#define m 20  // Size of hash table

int key[20], n;        // n: number of keys to insert
int *a;                // Dynamic hash table array
int index1;            // Temporary index for insertion
int count = 0;         // Number of elements currently in hash table

void linearprobing(int key)
{
    index1 = key % m;  // Initial hash index
    
    // Linear probing: find next empty slot (marked by -1)
    while (a[index1] != -1)
    {
        index1 = (index1 + 1) % m;  // Wrap around using modulo
    }
    
    a[index1] = key;   // Insert the key
    count++;           // Increment occupied count
}

void display()
{
    int i;
    
    if (count == 0)
    {
        printf("\nHash Table is empty\n");
        return;
    }
    
    printf("\nHash Table contents are:\n");
    for (i = 0; i < m; i++)
    {
        if (a[i] != -1)
            printf("\n T[%2d] --> %d", i, a[i]);
        else
            printf("\n T[%2d] --> empty", i);
    }
    printf("\n");
}

int main()
{
    int i;
    
    printf("\nEnter the number of four-digit key values: ");
    scanf("%d", &n);
    
    // Allocate hash table and initialize with -1 (empty marker)
    a = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
    {
        a[i] = -1;
    }
    
    printf("\nEnter the four-digit key values (K):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%4d", &key[i]);
    }
    
    // Insert each key using linear probing
    for (i = 0; i < n; i++)
    {
        if (count == m)
        {
            printf("\n-----Hash table is full. Cannot insert the record %d key-----\n", i + 1);
            break;
        }
        linearprobing(key[i]);
    }
    
    // Display the final hash table
    display();
    
    free(a);  // Free allocated memory
    return 0;
}
