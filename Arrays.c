#include <stdio.h>
#include <stdlib.h>

// Arrays are the the most basic data structrure of all data structures.
// It is a homogenous data structure (elements of the same type), and is stored on the memory contiguously.
// Size of elements per array type: 4 bytes - int, float; 8 bytes - double; 1 byte - character.

// Arrays has fixed size, in which we call Static Arrays, however, Dynamic Arrays are can either grow or shrink
// in terms of size. It has an initialized size, and as the dataset grows, the array allocates more memory
// to accommodate additional elements (often double the initial size).

// Multi-dimensional arrays are arrays that has n-th dimensions.
// 1D Arrays: Linear Form
// 2D Arrays: In a Tabular Form (has rows and columns)
// 3D Array: In a Cube Form (has blocks, rows, and columns)

void menu();
int access(int *arr, int i); // Accessing an element in an array is O(1)
int update(int *arr, int i, int new_val); // Updating an element in an array is O(1)
void search(int *arr, int key, int n); // Search for an element is O(N)
void show_arr(int *arr, int n);

int main()
{
    // Array Declaration - each element has a corresponding indexes for easier access;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int keyval, idx, key_srch;

    while(1) {

        int c;
        menu();
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                printf("Access Element: ");
                scanf("%d", &idx);
                printf("Element Accessed: %d\n", access(array, idx));
                break;

            case 2:
                printf("Update Index: ");
                scanf("%d", &idx);
                printf("Update Element: ");
                scanf("%d", &keyval);
                printf("Updated Element: %d\n", update(array, idx, keyval));
                break;

            case 3:
                printf("Search an element: ");
                scanf("%d", &key_srch);
                search(array, key_srch, 8);
                break;

            case 4:
                show_arr(array, 8) ;
                break;
        }
    }
    return 0;
}

void menu()
{
    printf("[1] - Access an Element\n");
    printf("[2] - Update an Element\n");
    printf("[3] - Search an Element\n");
    printf("[4] - Show Array\n");
}

int access(int *arr, int i)
{
    return arr[i];
}

int update(int *arr, int i, int new_val)
{
    arr[i] = new_val;

    return arr[i];
}

void search(int *arr, int key, int n)
{
    int flag = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            flag = 1;
            printf("Element Found");
            break;
        } else {
            printf("Element Not Found");
            break;
        }
    }
}

void show_arr(int *arr, int n)
{
    printf("\nElements: ");
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
