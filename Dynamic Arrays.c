#include <stdio.h>
#include <stdlib.h>

// Dynamic Arrays are arrays that can either grow or shrink.
// It can be pre-initialized with a number of size, and grows as the size = no. of data.

// In Memory:
// [1][2][3][4] -> Initial Array
// [1][2][3][4][5] -> Add elements: It copies the initial array and stores in the another copy of array.
// It is still contiguously allocated on the memory.

int main()
{
    // an initial size of the array is 5.
    int size = 5; 

    int *array = (int*)malloc(size * sizeof(int));

    if (!array) 
    {
        printf("Memory Allocation Failed.\n");
        return 1;
    }

    // Inserting 5 Elements to the Array.
    printf("Initial Elements: ");
    for (int i = 0; i < size; i++) 
    {
        array[i] = i + 2;
        printf("%d  ", array[i]);
    }

    // If that array is full, then, we will initialize another size for the array
    // in order to accommodate more values in the array.

    int resize = 10; 

    int *temp = (int*)realloc(array, resize * sizeof(int));

    if (!temp) {
        printf("Memory Reallocation Failed.\n");
        free(temp);
        return 1;
    }

    // then we assign the temporary array, back to its original array.
    array = temp; 
    
    printf("\n\nAdditional Elements: ");
    for (int i = 0; i < resize; i++) {
        array[i] = i + 2;
        printf("%d  ", array[i]);
    }

    free(array);
    return 0;
}