#include <stdio.h>
#include <stdlib.h>

// Connor McDaniel
// COP3502
// Lab Assignment 7
// 3/7/2024

typedef struct swapArray {
    int value;
    int swap;
} swapArray;

void printSwaps(swapArray* swaps, int size) { // prints swaps for every element
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", swaps[i].value, swaps[i].swap);
    }
}

void swap(swapArray* a, swapArray* b) { // swaps two elements
    swapArray temp = *a;
    *a = *b;
    *b = temp;
}

int totalSwaps(swapArray* swaps, int size) { // calculates total swaps for the array
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += swaps[i].swap;
    }
    return total / 2;
}

swapArray* swapBubbleSort(int* arr, int size) {
    swapArray* swaps = (swapArray*)malloc(sizeof(swapArray) * size);
    for (int i = 0; i < size; i++) {
        swaps[i].value = arr[i];
        swaps[i].swap = 0;
    }

    for (int i = 0; i < size - 1; i++) { // compares elements and swaps if its needed
        for (int j = 0; j < size - i - 1; j++) {
            if (swaps[j].value > swaps[j + 1].value) {
                swaps[j].swap++;
                swaps[j + 1].swap++;
                swap(&swaps[j], &swaps[j + 1]);
            }
        }
    }

    return swaps;
}

swapArray* swapSelectionSort(int* arr, int size) {
    swapArray* swaps = (swapArray*)malloc(sizeof(swapArray) * size);
    for (int i = 0; i < size; i++) {
        swaps[i].value = arr[i];
        swaps[i].swap = 0;
    }

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (swaps[j].value < swaps[min_index].value) { // finds min element in the portion that is unsorted
                min_index = j;
            }
        }
        if (min_index != i) { // swaps the min element with the first element
            swaps[min_index].swap++;
            swaps[i].swap++;
            swap(&swaps[i], &swaps[min_index]);
        }
    }

    return swaps;
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    swapArray* bubbleSort1 = swapBubbleSort(array1, size1);
    swapArray* bubbleSort2 = swapBubbleSort(array2, size2);

    printf("array1 bubble sort:\n");
    printSwaps(bubbleSort1, size1);
    printf("Total swaps: %d\n\n", totalSwaps(bubbleSort1, size1));
    printf("array2 bubble sort:\n");
    printSwaps(bubbleSort2, size2);
    printf("Total swaps: %d\n\n", totalSwaps(bubbleSort2, size2));

    free(bubbleSort1);
    free(bubbleSort2);

    swapArray* selectionSort1 = swapSelectionSort(array1, size1);
    swapArray* selectionSort2 = swapSelectionSort(array2, size2);

    printf("\narray1 selection sort:\n");
    printSwaps(selectionSort1, size1);
    printf("Total swaps: %d\n\n", totalSwaps(selectionSort1, size1));
    printf("array2 selection sort:\n");
    printSwaps(selectionSort2, size2);
    printf("Total swaps: %d\n\n", totalSwaps(selectionSort2, size2));

    free(selectionSort1);
    free(selectionSort2);

    return 0;
}
