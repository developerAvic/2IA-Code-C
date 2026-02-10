#include <stdio.h>
#include <stdlib.h>


// selectionsort takes an array and an integer as parameters
// the outer loop starts from zero till n-1,
// Why n-1 ? Because by the time you reach the last element, everything else is already sorted.
    //Assume the current element is the smallest. pos holds the index of the smallest value found so far.
    // inner loop  starts searching from elements after i
        // Compare current element a[j] with the smallest element found so far a[pos].
            // If a smaller element is found, update pos to remember its location.
    // check if the smallest element is not already in correct position
        // store the current element temporarily
        // Move smallest element to correct position.
        // Put previously stored element into the old smallest element position.
    
void selectionsort(int a[], int n)
{
    int i, j, pos, temp;

    for (i = 0; i < n - 1; i++){
        pos = i;  //Assume the current element is the smallest. pos holds the index of the smallest value found so far.
        for (j = i + 1; j < n; j++){
            if (a[j] < a[pos])
                pos = j;
        }
        if (i != pos){
            temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }
    }
}


// get the number of elements from user  - n
// allocate an dynamic array with the number of elements(n)
// take all the elements for the array.
// call the selection sort function with the array and the number of elements as arguments.
// print the sorted array
// free the dynamic memory

int main(){
    int *a, n, i;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    a = (int*) malloc(n * sizeof(int));

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selectionsort(a, n);

    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    free(a);
}
