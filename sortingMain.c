#include <stdio.h>
#include "sorting.h"
#define AMOUNT_TO_SORT 50

int main() {
    int arr[AMOUNT_TO_SORT];
    int *arrPtr = arr;
    for (int i=1; i<=AMOUNT_TO_SORT; i++) {
        printf("Enter a number: ");
        scanf("%d", arrPtr++);
        printf("\n");
    }

    insertion_sort(arr, AMOUNT_TO_SORT);

    arrPtr=arr;
    for(int i=0; i<AMOUNT_TO_SORT-1; i++) {
        printf("%d,", *arrPtr++);
    }
    printf("%d", *arrPtr++);
}